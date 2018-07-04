#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setPort(5432);
    db.setDatabaseName("Qt");
    db.setUserName("Qt_user");
    db.setPassword("Qt_user");

    if (db.open()) {
        qDebug() << "Connected!";
    } else {
        qDebug() << "Failed to connect.";
        return 0;
    }

    return a.exec();
}
