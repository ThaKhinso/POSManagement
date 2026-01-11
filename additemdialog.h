#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H
#include "UserData.h"
#include "productmodel.h"
#include <QDialog>

namespace Ui {
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(QWidget *parent = nullptr);
    void writeProductID(QString productID);
    void writeProductPrice(QString price);
    void writeProductName(QString name);
    void writePixmap(QByteArray& array);

    ~AddItemDialog();

private slots:
    void on_btnSelectImage_clicked();

    void on_addBtn_accepted();

private:
    Ui::AddItemDialog *ui;
    QString selectedImagePath;
    productModel m_model;
    // UserData m_data;

    QByteArray tempImageData;
};

#endif // ADDITEMDIALOG_H
