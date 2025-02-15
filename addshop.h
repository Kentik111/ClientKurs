#ifndef ADDSHOP_H
#define ADDSHOP_H

#include <QMainWindow>

namespace Ui {
class addshop;
}

class addshop : public QMainWindow
{
    Q_OBJECT

public:
    explicit addshop(QWidget *parent = nullptr);
    ~addshop();

private:
    Ui::addshop *ui;
};

#endif // ADDSHOP_H
