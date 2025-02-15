#ifndef CONNECTION_H
#define CONNECTION_H
#include "header.h"

class SocketRAII{
public:
    SocketRAII(int fd);
    ~SocketRAII();
    int get() const;
private:
    int fd_;
};

class Connection{
public:
    Connection(const char* server_ip, int port);
    ~Connection();
    void sendMessage(const string& message);
    string acceptMessage() ;
private:
    SocketRAII client_socket;
};

#endif // CONNECTION_H
