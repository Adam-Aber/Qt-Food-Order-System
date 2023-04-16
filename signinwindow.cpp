#include "signinwindow.h"
#include "ui_signinwindow.h"

SignInWindow::SignInWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignInWindow)
{
    ui->setupUi(this);

    balance = 100;
    size = 3;
    names = new string[size];
    passwords = new string[size];
    for (int i = 0; i < size; ++i) {
        names[i] = "user" + to_string(i+1);
        passwords[i] = "pass" + to_string(i+1);
    }
}

SignInWindow::~SignInWindow()
{
    delete ui;
}


void SignInWindow::on_pushButton_clicked()
{
    for (int i = 0; i < size; ++i) {
        if (ui->nameEdit->text() == QString::fromStdString(names[i]))
        {
            if (ui->passwordEdit->text() == QString::fromStdString(passwords[i])) {
                ui->errorMess->setText("Signed in successfully");
                ui->balanceSignIn->setText(QString::number(balance)+ " LE");

                Dialog dialog;
                dialog.setBalance(balance);
                dialog.setModal(true);
                dialog.exec();
                break;
            } else {
                ui->errorMess->setText("Correct name; wrong password");
                break;
            }
        }
        if (i == size - 1) {
            ui->errorMess->setText("Name does not exist");
        }
    }

}

