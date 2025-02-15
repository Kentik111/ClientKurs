#include "deleteshopwindow.h"
#include "ui_deleteshopwindow.h"
#include "mainmenu.h"
#include <QMessageBox>

deleteshopwindow::deleteshopwindow(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deleteshopwindow)
    , connection(connection)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
}

deleteshopwindow::~deleteshopwindow()
{
    delete ui;
}

void deleteshopwindow::on_exitButton_clicked()
{
    this->close();
    mainmenu window(connection);
    window.setModal(true);
    window.exec();
}



void deleteshopwindow::on_deleteShopButton_clicked()
{
    try {
        QString shopName = ui->shopNameLineEdit->text();
        QString shopAddress = ui->shopAddressLineEdit->text();
        if (shopName.isEmpty() || shopAddress.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, заполните все поля.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("5|%1|%2").arg(shopName).arg(shopAddress);
        connection->sendMessage(message.toStdString()); // Отправляем объединенное сообщение

        QString result = QString::fromStdString(connection->acceptMessage()); // Принимаем ответ от сервера
        QMessageBox::information(this, "Результат", result); // Выводим ответ сервера
    }
    catch (const runtime_error& error)
    {
        QMessageBox::critical(this, "Ошибка", error.what());
    }
}

