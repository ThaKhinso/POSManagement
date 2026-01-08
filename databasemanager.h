#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class DatabaseManager
{
public:
    DatabaseManager();
    bool connectToDatabase();

    //This is here for sole purpose of testing
    void setupFirstTime();

    QSqlDatabase* getDB() {
        return &db;
    }

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
