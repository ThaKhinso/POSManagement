#include "databasemanager.h"

DatabaseManager::DatabaseManager() {
    connectToDatabase();
}

bool DatabaseManager::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("hotel_system.db");
    if (!db.open()) {
        qDebug() << "Error: connection with the database failed:" << db.lastError() << "\n";
        return false;
    }
    qDebug() << "Database connected successfully\n";
    return true;
}

void DatabaseManager::setupFirstTime()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE, "
               "password TEXT)");

    // Optional: Add a default admin if table is empty
    query.exec("INSERT OR IGNORE INTO users (username, password) VALUES ('admin', 'password123')");
}
