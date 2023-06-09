#include "cart.h"
#include "ui_cart.h"

Cart::Cart(vector<QString> cartElements, vector<QString> ElementsPrice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cart)
{
    ui->setupUi(this);

    vector<QString>::iterator ptr;  // Iterator over cart items
    vector<QString>::iterator ptr2 = ElementsPrice.begin(); // Iterator over cart items' prices

    // Display each item and its price
    for (ptr = cartElements.begin(); ptr != cartElements.end(); ++ptr) {
        ui->textEdit->append(*ptr); // Display the item name
        ui->textEdit->setText(ui->textEdit->toPlainText() + ": " + *ptr2);  // Display the corresponding price
        ptr2++;
    }

    totalPrice(ptr2, ElementsPrice); // Calculate and display the total price
}


void Cart::totalPrice(vector<QString>::iterator ptr, vector<QString> ElementsPrice) {
    // Calculate and display the total price
    total = 0;
    for (ptr = ElementsPrice.begin() ; ptr != ElementsPrice.end(); ++ptr) {
        total += (*ptr).toInt();    // Add every price in the price vector to the total
    }
    ui->totalPrice->setText(QString::number(total) + " LE");    // Display the total
}


void Cart::setBalance(int b) {
    balance = b;
    // Display the balance
    ui->accountBalance->setText(QString::number(balance) + " LE");
}



Cart::~Cart()
{
    delete ui;
}

void Cart::on_buyItems_clicked() // Buy Items
{
    if (balance < total) {
        ui->rechargeMessage->setText("Balance not enough, recharge");
    } else {
        ui->rechargeMessage->setText("Purchased Successfully");
        balance = balance - total;  // Calculate the new balance
        setBalance(balance);
    }
}


void Cart::on_pushButton_clicked() // Recharge balance
{
    if (ui->rechargeBalance->text().toInt() < 0) {
        ui->rechargeBalance->setText("Unvalid: negative number");
    } else {
        balance = balance + ui->rechargeBalance->text().toInt();  // Calculate the new balance
        setBalance(balance);
        ui->rechargeBalance->setText("");
    }
}

