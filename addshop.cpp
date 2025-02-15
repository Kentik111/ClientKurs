#include "addshop.h"
#include "ui_addshop.h"

addshop::addshop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addshop)
{
    ui->setupUi(this);
}

addshop::~addshop()
{
    delete ui;
}
