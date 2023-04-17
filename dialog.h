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

    void setBalance(int &b); // Display the balance

    ~Dialog();

private slots:

    void on_ChickenBox_activated(int index);  // Displays selected item's details

    void on_MeatBox_activated(int index);   // Displays selected item's details

    void on_addToCart_clicked(); // Adds item to cart

    void on_pushButton_clicked();  // Views the cart

private:
    Ui::Dialog *ui;

    int* meatPrice;     // Array containing the prices of the options in the meat combobox
    int* chickenPrice;  // Array containing the prices of the options in the chicken combobox
    int balance;    //   User's balance
    int size;   // Number of options
    string* meatOptionsName; // Array containing the options in the chicken combobox
    string* chickenOptionsName; // Array containing the options in the meat combobox
    vector<QString> cartElements; // Vector to contain the names of items in the cart
    vector<QString> ElementsPrice; // Vector to contain the prices of the names of items in the cart
};

#endif // DIALOG_H
