#ifndef CART_H
#define CART_H

#include <QDialog>
#include <vector>
using namespace std;

namespace Ui {
class Cart;
}
class Cart : public QDialog
{
    Q_OBJECT

public:
    explicit Cart(vector<QString> cartElements, vector<QString> ElementsPrice, QWidget *parent = nullptr);

    void totalPrice(vector<QString>::iterator ptr, vector<QString> ElementsPrice);

    void setBalance(int b);



    ~Cart();

private slots:
    void on_buyItems_clicked();

    void on_pushButton_clicked();

private:
    Ui::Cart *ui;

    int total;
    int balance;
};

#endif // CART_H
