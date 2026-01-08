#include "mainwindow.h"

#include <QApplication>
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager database;
    database.setupFirstTime();
    UserData userData = {
        .db = *database.getDB()
    };

    MainWindow w(userData);


    w.show();
    return a.exec();
}
