#include "findshopwindow.h"
#include "ui_findshopwindow.h"
#include "mainmenu.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

findshopwindow::findshopwindow(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::findshopwindow)
    , connection(connection)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
}

findshopwindow::~findshopwindow()
{
    delete ui;
}

void findshopwindow::on_pushButton_3_clicked()
{
    this->close();
    mainmenu window(connection);
    window.setModal(true);
    window.exec();
}


void findshopwindow::on_findShopButton_clicked()
{
    try {
        QString shopName = ui->shopLine->text();
        if (shopName.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, введите название магазина.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("3|%1").arg(shopName);
        connection->sendMessage(message.toStdString()); // Отправляем объединенное сообщение

        QString result = QString::fromStdString(connection->acceptMessage()); // Принимаем ответ от сервера
        QMessageBox::information(this, "Результат", result); // Выводим ответ сервера
    }
    catch (const runtime_error& error)
    {
        QMessageBox::critical(this, "Ошибка", error.what());
    }
}


void findshopwindow::on_makeFileButton_clicked()
{
    try {
        QString shopName = ui->shopLine->text();
        QString pathName = ui->pathLine->text();
        if (shopName.isEmpty() || pathName.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, заполните все поля.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("3|%1").arg(shopName);
        connection->sendMessage(message.toStdString()); // Отправляем объединенное сообщение

        QString result = QString::fromStdString(connection->acceptMessage()); // Принимаем ответ от сервера

        // Запись результата в файл
        QFile file(pathName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << result; // Записываем результат в файл
            file.close();
            QMessageBox::information(this, "Успех", "Результат успешно записан в файл.");
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи.");
        }
    }
    catch (const runtime_error& error)
    {
        QMessageBox::critical(this, "Ошибка", error.what());
    }
}

