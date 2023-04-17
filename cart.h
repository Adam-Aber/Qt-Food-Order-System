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

    void totalPrice(vector<QString>::iterator ptr, vector<QString> ElementsPrice); // Calculate and display the total price

    void setBalance(int b); // Display the balance



    ~Cart();

private slots:
    void on_buyItems_clicked(); // Buys the items

    void on_pushButton_clicked();  // Recharges balance

private:
    Ui::Cart *ui;

    int total;  // The total price of items in the cart
    int balance;    // User's balance
};

#endif // CART_H
