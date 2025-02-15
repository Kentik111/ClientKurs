#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "addshopwindow.h"
#include "addproductwindow.h"
#include "findshopwindow.h"
#include "findproductwindow.h"
#include "deleteshopwindow.h"
#include "deleteproductwindow.h"
#include <QMessageBox>
#include <QPixmap>

mainmenu::mainmenu(Connection *connection, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainmenu)
    , connection(connection)

{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white;");
    QPixmap pix(":/mg/img/welcome.png");
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

mainmenu::~mainmenu()
{
    delete ui;
}



void mainmenu::on_pushButton_2_clicked()
{
    this->close();
    addshopwindow window(connection);
    window.setModal(true);
    window.exec();
}


void mainmenu::on_pushButton_clicked()
{
    this->close();
    addproductwindow window(connection);
    window.setModal(true);
    window.exec();
}


void mainmenu::on_pushButton_5_clicked()
{
    QMessageBox::StandardButton exitButton = QMessageBox::question(this, "Выход", "Вы уверены, что хотите выйти?", QMessageBox::Yes | QMessageBox::No);
    if(exitButton == QMessageBox::Yes){
        QApplication::quit();
    }
}


void mainmenu::on_pushButton_3_clicked()
{
    this->close();
    findshopwindow window(connection);
    window.setModal(true);
    window.exec();
}


void mainmenu::on_pushButton_4_clicked()
{
    this->close();
    findproductwindow window(connection);
    window.setModal(true);
    window.exec();
}


void mainmenu::on_pushButton_8_clicked()
{
    this->close();
    deleteshopwindow window(connection);
    window.setModal(true);
    window.exec();
}


void mainmenu::on_pushButton_9_clicked()
{
    this->close();
    deleteproductwindow window(connection);
    window.setModal(true);
    window.exec();
}

