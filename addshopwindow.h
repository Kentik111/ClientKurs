#ifndef ADDSHOPWINDOW_H
#define ADDSHOPWINDOW_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class addshopwindow;
}

class addshopwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addshopwindow(Connection* connection, QWidget *parent = nullptr);
    ~addshopwindow();

private slots:
    void on_addButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::addshopwindow *ui;
    Connection *connection;
};

#endif // ADDSHOPWINDOW_H
