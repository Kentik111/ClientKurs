#ifndef FINDSHOPWINDOW_H
#define FINDSHOPWINDOW_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class findshopwindow;
}

class findshopwindow : public QDialog
{
    Q_OBJECT

public:
    explicit findshopwindow(Connection* connection, QWidget *parent = nullptr);
    ~findshopwindow();

private slots:
    void on_pushButton_3_clicked();

    void on_findShopButton_clicked();

    void on_makeFileButton_clicked();

private:
    Ui::findshopwindow *ui;
    Connection *connection;
};

#endif // FINDSHOPWINDOW_H
