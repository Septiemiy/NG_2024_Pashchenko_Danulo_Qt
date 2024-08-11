#ifndef CARCATALOG_H
#define CARCATALOG_H

#include <QMainWindow>
#include <QVector>
#include "Car.h"
#include <QDebug>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class CarCatalog;
}
QT_END_NAMESPACE

class CarCatalog : public QMainWindow
{
    Q_OBJECT

public:
    CarCatalog(QWidget *parent = nullptr);
    ~CarCatalog();

public:
    void initCars();
    void initCarsTabs();
    void setFilter(QString filterType);

public slots:
    void defineFilteringMethod();

private:
    Ui::CarCatalog *ui;

    QVector<Car> m_cars;

    enum Filter_Variant
    {
        None,
        Type,
        Producer,
        Price
    };
};
#endif // CARCATALOG_H
