#include "signinwindow.h"
#include "ui_signinwindow.h"

SignInWindow::SignInWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignInWindow)
{
    ui->setupUi(this);

    size = 3;

    // Create the arrays in the heap
    names = new string[size];
    passwords = new string[size];
    balance = new int[size];

    // Initialize the arrays with each account's information
    for (int i = 0; i < size; ++i) {
        names[i] = "user" + to_string(i+1);
        passwords[i] = "pass" + to_string(i+1);
        balance[i] = 100 + i;
    }
}

SignInWindow::~SignInWindow()
{
    delete ui;
}


void SignInWindow::on_pushButton_clicked()
{
    for (int i = 0; i < size; ++i) {
        if (ui->nameEdit->text() == QString::fromStdString(names[i]))   // Check if the name is correct
        {
            if (ui->passwordEdit->text() == QString::fromStdString(passwords[i])) {   // Check if the password is correct
                ui->errorMess->setText("Signed in successfully");
                ui->balanceSignIn->setText(QString::number(balance[i])+ " LE");     // Set the balance

                Dialog dialog;  // Create a new window to choose items
                dialog.setBalance(balance[i]);  // Pass the balance to the new window
                dialog.setModal(true);
                dialog.exec();
                break;
            } else {
                ui->errorMess->setText("Correct name; wrong password"); // Case password is wrong
                break;
            }
        }
        if (i == size - 1) {
            ui->errorMess->setText("Name does not exist");  // Case name is wrong
        }
    }

}

