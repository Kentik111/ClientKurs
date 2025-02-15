#ifndef DELETEPRODUCTWINDOW_H
#define DELETEPRODUCTWINDOW_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class deleteproductwindow;
}

class deleteproductwindow : public QDialog
{
    Q_OBJECT

public:
    explicit deleteproductwindow(Connection* connection, QWidget *parent = nullptr);
    ~deleteproductwindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deleteproductwindow *ui;
    Connection *connection;
};

#endif // DELETEPRODUCTWINDOW_H
