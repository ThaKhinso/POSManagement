#ifndef PRODUCTCARD_H
#define PRODUCTCARD_H
#include <QFrame>
#include "productmodel.h"

class ProductCard : public QFrame
{
    Q_OBJECT
public:
    void contextMenuEvent(QContextMenuEvent* event);
    explicit ProductCard(productModel &product, QWidget *parent = nullptr);

private:
    productModel model;
signals:
    void productChanged(); // Signal to notify parent to reload
};

#endif // PRODUCTCARD_H
