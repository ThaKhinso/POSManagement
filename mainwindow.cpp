#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QMessageBox>

QString readFile(const QString &fileName) {
    QFile file(fileName);

    // Attempt to open the file in ReadOnly and Text mode
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading:" << fileName;
        return QString();
    }

    // Read everything and convert to QString
    QString content = file.readAll();

    file.close();
    return content;
}

MainWindow::MainWindow(UserData &userData, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->m_userData = userData;
    QFile file(":/style.qss");
    if(file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&file);
        QString style = in.readAll();

        this->setStyleSheet(style);
        file.close();
    } else {
        qInfo() << "Could not open file. " << "\n";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user = ui->nameInput->text();
    QString pass = ui->passInput->text();
    QSqlQuery query(QSqlDatabase::database(this->m_userData.db.databaseName()));
    query.prepare("SELECT password FROM users WHERE username = :user");
    query.bindValue(":user", user);
        if (query.exec() && query.next()) {
        QString dbPassword = query.value(0).toString();
            qInfo() << dbPassword << "\n";
            qInfo() << pass << "\n";
        if (dbPassword == pass) {
            // QMessageBox::warning(this, "Login success", "nigger"); // Login success!
            ui->stackedWidget->setCurrentIndex(1);
        } else {
            QMessageBox::warning(this, "Error", "Incorrect password.");
        }
    } else {
        QMessageBox::warning(this, "Error", "User not found.");
    }
}


void MainWindow::on_loginButton_clicked()
{
    on_pushButton_clicked();
}

