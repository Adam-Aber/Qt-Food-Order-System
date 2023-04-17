#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    size = 4;

    // Create the arrays
    chickenOptionsName = new string[size];
    meatOptionsName = new string[size];
    meatPrice = new int[size];
    chickenPrice = new int[size];

    // Set default values to nothing is selected
    ui->ChickenBox->setCurrentIndex(-1);
    ui->MeatBox->setCurrentIndex(-1);

    // Fill up the Chicken combobox

    // Choose the meal names
    chickenOptionsName[0] = "Chicken Burger";
    chickenOptionsName[1] = "Chicken Filet";
    chickenOptionsName[2] = "Chicken Chimichanga";
    chickenOptionsName[3] = "Chicken Tacos";

    // Choose the meal prices
    chickenPrice[0] = 11;
    chickenPrice[1] = 10;
    chickenPrice[2] = 14;
    chickenPrice[3] = 16;

    // Add the meal names and prices to the chicken options combobox
    for (int i = 0; i < size; ++i) {
        ui->ChickenBox->addItem(QString::fromStdString(chickenOptionsName[i]), QVariant::fromValue(i)); // Convert data types according to function
        ui->ChickenBox->setItemData(i, QString::number(chickenPrice[i]));
    }


    // Fill up the Meat combobox

    // Choose the meal names
    meatOptionsName[0] = "Beef Burger";
    meatOptionsName[1] = "Steak";
    meatOptionsName[2] = "Beef Sausage";
    meatOptionsName[3] = "Beef Pizza";

    // Choose the meal prices
    meatPrice[0] = 14;
    meatPrice[1] = 25;
    meatPrice[2] = 18;
    meatPrice[3] = 12;

    // Add the meal names and prices to the chicken options combobox
    for (int i = 0; i < size; ++i) {
        ui->MeatBox->addItem(QString::fromStdString(meatOptionsName[i]), QVariant::fromValue(i));
        ui->MeatBox->setItemData(i, QString::number(meatPrice[i]));
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_ChickenBox_activated(int index)
{
    ui->itemPrice->setText(ui->ChickenBox->itemData(index).toString()); // Display meal price
    ui->MeatBox->setCurrentIndex(-1); // Unselect the last value from other combobox
}


void Dialog::on_MeatBox_activated(int index)
{
    ui->itemPrice->setText(ui->MeatBox->itemData(index).toString()); // Display meal price
    ui->ChickenBox->setCurrentIndex(-1); // Unselect the last value from other combobox
}

void Dialog::setBalance(int& b) {
    balance = b;
    // Display the balance
    ui->accountBalance->setText(QString::number(balance) + " LE");
}

void Dialog::on_addToCart_clicked()
{
    if (ui->ChickenBox->currentIndex() > -1) {
        // This is the case where the chicken combobox is selected
        ui->itemsNumber->setText(QString::number((ui->itemsNumber->text()).toInt()+1)); // Increment the number of items in the cart
        cartElements.push_back(ui->ChickenBox->currentText()); // Add the element added to cart to the vector of items
        ElementsPrice.push_back(ui->ChickenBox->itemData(ui->ChickenBox->currentIndex()).toString()); // Add the price of the element added to cart to the vector of prices
    } else if (ui->MeatBox->currentIndex() > -1) {
        // This is the case where the chicken combobox is selected
        ui->itemsNumber->setText(QString::number((ui->itemsNumber->text()).toInt()+1)); // Increment the number of items in the cart
        cartElements.push_back(ui->MeatBox->currentText()); // Add the element added to cart to the vector of items
        ElementsPrice.push_back(ui->MeatBox->itemData(ui->MeatBox->currentIndex()).toString()); // Add the price of the element added to cart to the vector of prices
    } else {
        // This is the case where no combobox is selected
        ui->chooseCart->setText("Choose an item first");
    }
}


void Dialog::on_pushButton_clicked()
{
    Cart cart(cartElements, ElementsPrice); // Create a new window to view the cart
    cart.setBalance(balance);   // Pass the balance
    cart.setModal(true);
    cart.exec();
}

