#include "deleteproductwindow.h"
#include "ui_deleteproductwindow.h"
#include "mainmenu.h"
#include <QMessageBox>

deleteproductwindow::deleteproductwindow(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deleteproductwindow)
    , connection(connection)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
}

deleteproductwindow::~deleteproductwindow()
{
    delete ui;
}

void deleteproductwindow::on_pushButton_2_clicked()
{
    this->close();
    mainmenu window(connection);
    window.setModal(true);
    window.exec();
}



void deleteproductwindow::on_pushButton_clicked()
{
    try {
        QString shopName = ui->shopLine->text();
        QString shopAddress = ui->addresLine->text();
        QString productName = ui->productLine->text();
        if (shopName.isEmpty() || shopAddress.isEmpty() || productName.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, заполните все поля.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("6|%1|%2|%3").arg(shopName).arg(shopAddress).arg(productName);
        connection->sendMessage(message.toStdString()); // Отправляем объединенное сообщение

        QString result = QString::fromStdString(connection->acceptMessage()); // Принимаем ответ от сервера
        QMessageBox::information(this, "Результат", result); // Выводим ответ сервера
    }
    catch (const runtime_error& error)
    {
        QMessageBox::critical(this, "Ошибка", error.what());
    }
}

