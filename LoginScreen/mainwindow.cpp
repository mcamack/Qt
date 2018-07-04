#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("Qt");
    db.setUserName("Qt_user");
    db.setPassword("Qt_user");

    if (db.open()) {
        qDebug() << "Connected!";
    } else {
        qDebug() << "Failed to connect.";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username = ui->userInput->text();
    QString password = ui->passwordInput->text();

    QString cmd = "SELECT * FROM users WHERE username = '" + username
            + "' AND password = '" + password + "' AND status = 0";
    QSqlQuery query(db);
    if (query.exec(cmd)){
        if(query.size() > 0){
            QMessageBox::information(this, "Login Success!", "You have successfully logged in.");
        } else {
            QMessageBox::information(this, "Login failed.", "Failed to login, try again.");
        }

    }
}
