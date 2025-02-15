#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "connection.h"
namespace Ui {
class mainmenu;
}

class mainmenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainmenu(Connection* connection, QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::mainmenu *ui;
    Connection *connection;
};

#endif // MAINMENU_H
