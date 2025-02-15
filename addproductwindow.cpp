#include "addproductwindow.h"
#include "ui_addproductwindow.h"
#include "mainmenu.h"
#include <QMessageBox>
addproductwindow::addproductwindow(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addproductwindow)
    , connection(connection)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
}

addproductwindow::~addproductwindow()
{
    delete ui;
}



void addproductwindow::on_pushButton_2_clicked()
{
    this->close();
    mainmenu window(connection);
    window.setModal(true);
    window.exec();
}


void addproductwindow::on_addProduct_clicked()
{
    try {
        QString shopName = ui->shopLine->text();
        QString shopAddress = ui->addresLine->text();
        QString productName = ui->productLine->text();
        QString price = ui->priceLine->text();
        QString quantity = ui->quantLine->text();
        if (shopName.isEmpty() || shopAddress.isEmpty() || productName.isEmpty() || price.isEmpty() || quantity.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, заполните все поля.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("2|%1|%2|%3|%4|%5").arg(shopName).arg(shopAddress).arg(productName).arg(price).arg(quantity);
        connection->sendMessage(message.toStdString()); // Отправляем объединенное сообщение

        QString result = QString::fromStdString(connection->acceptMessage()); // Принимаем ответ от сервера
        QMessageBox::information(this, "Результат", result); // Выводим ответ сервера
    }
    catch (const runtime_error& error)
    {
        QMessageBox::critical(this, "Ошибка", error.what());
    }
}

