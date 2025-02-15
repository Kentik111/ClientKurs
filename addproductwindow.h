#ifndef ADDPRODUCTWINDOW_H
#define ADDPRODUCTWINDOW_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class addproductwindow;
}

class addproductwindow : public QDialog
{
    Q_OBJECT

public:
    explicit addproductwindow(Connection* connection, QWidget *parent = nullptr);
    ~addproductwindow();

private slots:

    void on_pushButton_2_clicked();

    void on_addProduct_clicked();

private:
    Ui::addproductwindow *ui;
    Connection *connection;
};

#endif // ADDPRODUCTWINDOW_H
