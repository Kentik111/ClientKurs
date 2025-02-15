#include "findproductwindow.h"
#include "ui_findproductwindow.h"
#include "mainmenu.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

findproductwindow::findproductwindow(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::findproductwindow)
    , connection(connection)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
}

findproductwindow::~findproductwindow()
{
    delete ui;
}

void findproductwindow::on_exitButton_clicked()
{
    this->close();
    mainmenu window(connection);
    window.setModal(true);
    window.exec();
}


void findproductwindow::on_findProductButton_clicked()
{
    try {
        QString productName = ui->productLine->text();
        if (productName.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, введите название товара.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("4|%1").arg(productName);
        connection->sendMessage(message.toStdString()); // Отправляем объединенное сообщение

        QString result = QString::fromStdString(connection->acceptMessage()); // Принимаем ответ от сервера
        QMessageBox::information(this, "Результат", result); // Выводим ответ сервера
    }
    catch (const runtime_error& error)
    {
        QMessageBox::critical(this, "Ошибка", error.what());
    }
}


void findproductwindow::on_makeFileButton_clicked()
{
    try {
        QString productName = ui->productLine->text();
        QString pathName = ui->pathLine->text();
        if (productName.isEmpty() || pathName.isEmpty()) {
            QMessageBox::warning(this, "Внимание", "Пожалуйста, заполните все поля.");
            return;
        }

        // Объединяем данные в одно сообщение с разделителем
        QString message = QString("4|%1").arg(productName);
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

