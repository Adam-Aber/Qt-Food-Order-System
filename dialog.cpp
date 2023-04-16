#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    size = 4;
    chickenOptionsName = new string[size];
    meatOptionsName = new string[size];
    meatPrice = new int[size];
    chickenPrice = new int[size];

    // Set default values to nothing is selected
    ui->ChickenBox->setCurrentIndex(-1);
    ui->MeatBox->setCurrentIndex(-1);

    // Fill up the Chicken combobox
    chickenOptionsName[0] = "Chicken Burger";
    chickenOptionsName[1] = "Chicken Filet";
    chickenOptionsName[2] = "Chicken Chimichanga";
    chickenOptionsName[3] = "Chicken Tacos";

    chickenPrice[0] = 11;
    chickenPrice[1] = 10;
    chickenPrice[2] = 14;
    chickenPrice[3] = 16;

    for (int i = 0; i < size; ++i) {
        ui->ChickenBox->addItem(QString::fromStdString(chickenOptionsName[i]), QVariant::fromValue(i));
        ui->ChickenBox->setItemData(i, QString::number(chickenPrice[i]));
    }


    // Fill up the Meat combobox

    meatOptionsName[0] = "Beef Burger";
    meatOptionsName[1] = "Steak";
    meatOptionsName[2] = "Beef Sausage";
    meatOptionsName[3] = "Beef Pizza";

    meatPrice[0] = 14;
    meatPrice[1] = 25;
    meatPrice[2] = 18;
    meatPrice[3] = 12;

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
    ui->itemPrice->setText(ui->ChickenBox->itemData(index).toString());
    ui->MeatBox->setCurrentIndex(-1);
}


void Dialog::on_MeatBox_activated(int index)
{
    ui->itemPrice->setText(ui->MeatBox->itemData(index).toString());
    ui->ChickenBox->setCurrentIndex(-1);
}

void Dialog::setBalance(int b) {
    balance = b;
    // Display the balance
    ui->accountBalance->setText(QString::number(balance) + " LE");
}

void Dialog::on_addToCart_clicked()
{
    if (ui->ChickenBox->currentIndex() > -1) {
        ui->itemsNumber->setText(QString::number((ui->itemsNumber->text()).toInt()+1));
        cartElements.push_back(ui->ChickenBox->currentText());
        ElementsPrice.push_back(ui->ChickenBox->itemData(ui->ChickenBox->currentIndex()).toString());
    } else if (ui->MeatBox->currentIndex() > -1) {
        ui->itemsNumber->setText(QString::number((ui->itemsNumber->text()).toInt()+1));
        cartElements.push_back(ui->MeatBox->currentText());
        ElementsPrice.push_back(ui->MeatBox->itemData(ui->MeatBox->currentIndex()).toString());
    } else {
        ui->chooseCart->setText("Choose an item first");
    }
}


void Dialog::on_pushButton_clicked()
{
    Cart cart(cartElements, ElementsPrice);
    cart.setBalance(balance);
    cart.setModal(true);
    cart.exec();
}

