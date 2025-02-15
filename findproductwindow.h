#ifndef FINDPRODUCTWINDOW_H
#define FINDPRODUCTWINDOW_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class findproductwindow;
}

class findproductwindow : public QDialog
{
    Q_OBJECT

public:
    explicit findproductwindow(Connection* connection, QWidget *parent = nullptr);
    ~findproductwindow();

private slots:
    void on_exitButton_clicked();

    void on_findProductButton_clicked();

    void on_makeFileButton_clicked();

private:
    Ui::findproductwindow *ui;
    Connection *connection;
};

#endif // FINDPRODUCTWINDOW_H
