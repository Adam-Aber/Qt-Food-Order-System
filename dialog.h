#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>
#include <vector>
#include "cart.h"
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    void setBalance(int b);

    ~Dialog();

private slots:

    void on_ChickenBox_activated(int index);

    void on_MeatBox_activated(int index);

    void on_addToCart_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int* meatPrice;
    int* chickenPrice;
    int balance;
    int size;
    string* meatOptionsName;
    string* chickenOptionsName;
    vector<QString> cartElements;
    vector<QString> ElementsPrice;
};

#endif // DIALOG_H
