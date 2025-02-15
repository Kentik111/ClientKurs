#include "addshopwindow.h"
#include "ui_addshopwindow.h"
#include "mainmenu.h"
#include <QMessageBox>
addshopwindow::addshopwindow(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addshopwindow)
    , connection(connection)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
}

addshopwindow::~addshopwindow()
{
    delete ui;
}

void addshopwindow::on_addButton_clicked()
{
    try {
        QString shopName = ui->shopNameLineEdit->text();
        QString shopAddress = ui->shopAddressLineEdit->text();
        if (shopName.isEmpty() || shopAddress.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, заполните все поля.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("1|%1|%2").arg(shopName).arg(shopAddress);
        connection->sendMessage(message.toStdString()); // Отправляем объединенное сообщение

        QString result = QString::fromStdString(connection->acceptMessage()); // Принимаем ответ от сервера
        QMessageBox::information(this, "Результат", result); // Выводим ответ сервера    
    }
    catch (const runtime_error& error)
    {
        QMessageBox::critical(this, "Ошибка", error.what());
    }
}


void addshopwindow::on_exitButton_clicked()
{
    this->close(); // Закрываем окно добавления магазина
    mainmenu window(connection);
    window.setModal(true);
    window.exec();

}

