#ifndef DELETESHOPWINDOW_H
#define DELETESHOPWINDOW_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class deleteshopwindow;
}

class deleteshopwindow : public QDialog
{
    Q_OBJECT

public:
    explicit deleteshopwindow(Connection* connection, QWidget *parent = nullptr);
    ~deleteshopwindow();

private slots:
    void on_exitButton_clicked();

    void on_deleteShopButton_clicked();

private:
    Ui::deleteshopwindow *ui;
    Connection *connection;
};

#endif // DELETESHOPWINDOW_H
