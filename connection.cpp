#include "connection.h"

SocketRAII::SocketRAII(int fd) : fd_(fd) {}

SocketRAII::~SocketRAII(){
    if (close(fd_) < 0) {
        cerr << "Ошибка при закрытии сокета" << endl;
    }
}

int SocketRAII:: get() const { return fd_; }

Connection::Connection(const char* server_ip, int port) : client_socket(socket(AF_INET, SOCK_STREAM, 0)) {
    if (client_socket.get() < 0) {
        throw runtime_error("Ошибка создания сокета");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        throw runtime_error("Ошибка преобразования IP-адреса");
    }

    if (connect(client_socket.get(), (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        throw runtime_error("Ошибка подключения к серверу");
    }

    cout << "Подключено к серверу " << server_ip << ":" << port << endl;
}

Connection::~Connection(){
    cout << "Соединение разорвано" << endl;
}

void Connection::sendMessage(const string& message) {
    if (send(client_socket.get(), message.c_str(), message.size(), 0) < 0) {
        throw runtime_error("Ошибка отправки сообщения серверу");
    }
}

string Connection::acceptMessage() {
    char buffer[1024] = {0};
    int bytes_received = recv(client_socket.get(), buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        throw runtime_error("Ошибка при получении сообщения от сервера");
    }
    return string(buffer);
}

