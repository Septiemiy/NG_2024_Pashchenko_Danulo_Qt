#include "carcatalog.h"
#include "ui_carcatalog.h"

CarCatalog::CarCatalog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CarCatalog)
{
    ui->setupUi(this);

    initCars();
    initCarsTabs();

    ui->cb_filteringOptions->addItem("None");
    ui->cb_filteringOptions->addItem("Type");
    ui->cb_filteringOptions->addItem("Producer");
    ui->cb_filteringOptions->addItem("< Price");

    connect(ui->b_filter, &QPushButton::clicked, this, &CarCatalog::defineFilteringMethod);
}

CarCatalog::~CarCatalog()
{
    delete ui;
}

void CarCatalog::initCars()
{
    Car touareg;
    touareg.setProducer("Volkswagen");
    touareg.setPrice(85036);
    touareg.setType("SUV");
    touareg.setModelRange("Touareg");
    touareg.setNumberSeats(5);
    touareg.setColor("White");
    m_cars.append(touareg);

    Car transit;
    transit.setProducer("Ford");
    transit.setPrice(45183);
    transit.setType("Van");
    transit.setModelRange("Transit");
    transit.setNumberSeats(2);
    transit.setColor("White");
    m_cars.append(transit);

    Car hilux;
    hilux.setProducer("Toyota");
    hilux.setPrice(41753);
    hilux.setType("Pickup");
    hilux.setModelRange("Hilux");
    hilux.setNumberSeats(5);
    hilux.setColor("White");
    m_cars.append(hilux);
}

void CarCatalog::initCarsTabs()
{
    ui->tw_cars->setTabText(0, m_cars[0].getModelRange());
    ui->e_producer->setText(m_cars[0].getProducer());
    ui->e_price->setText(QString::number(m_cars[0].getPrice()));
    ui->e_type->setText(m_cars[0].getType());
    ui->e_model_range->setText(m_cars[0].getModelRange());
    ui->e_number_seats->setText(QString::number(m_cars[0].getNumberSeats()));
    ui->e_color->setText(m_cars[0].getColor());

    ui->tw_cars->setTabText(1, m_cars[1].getModelRange());
    ui->e_producer_two->setText(m_cars[1].getProducer());
    ui->e_price_two->setText(QString::number(m_cars[1].getPrice()));
    ui->e_type_two->setText(m_cars[1].getType());
    ui->e_model_range_two->setText(m_cars[1].getModelRange());
    ui->e_number_seats_two->setText(QString::number(m_cars[1].getNumberSeats()));
    ui->e_color_two->setText(m_cars[1].getColor());

    ui->tw_cars->setTabText(2, m_cars[2].getModelRange());
    ui->e_producer_three->setText(m_cars[2].getProducer());
    ui->e_price_three->setText(QString::number(m_cars[2].getPrice()));
    ui->e_type_three->setText(m_cars[2].getType());
    ui->e_model_range_three->setText(m_cars[2].getModelRange());
    ui->e_number_seats_three->setText(QString::number(m_cars[2].getNumberSeats()));
    ui->e_color_three->setText(m_cars[2].getColor());
}

void CarCatalog::setProducerFilter()
{
    QString filterText = ui->e_filteringField->toPlainText();
    for(int index = 0; index < m_cars.count(); index++)
    {
        if(filterText != m_cars[index].getProducer())
        {
            ui->tw_cars->setTabVisible(index, false);
        }
        else
        {
            ui->tw_cars->setTabVisible(index, true);
        }
    }
}

void CarCatalog::setTypeFilter()
{
    QString filterText = ui->e_filteringField->toPlainText();
    for(int index = 0; index < m_cars.count(); index++)
    {
        if(filterText != m_cars[index].getType())
        {
            ui->tw_cars->setTabVisible(index, false);
        }
        else
        {
            ui->tw_cars->setTabVisible(index, true);
        }
    }
}

void CarCatalog::setPriceFilter()
{
    QString filterText = ui->e_filteringField->toPlainText();
    for(int index = 0; index < m_cars.count(); index++)
    {
        if(filterText.toFloat() < m_cars[index].getPrice())
        {
            ui->tw_cars->setTabVisible(index, false);
        }
        else
        {
            ui->tw_cars->setTabVisible(index, true);
        }
    }
}

void CarCatalog::setNoneFilter()
{
    for(int index = 0; index < ui->tw_cars->count(); index++)
    {
        ui->tw_cars->setTabVisible(index, true);
    }
}

void CarCatalog::defineFilteringMethod()
{
    int filteringMethod = ui->cb_filteringOptions->currentIndex();
    switch(filteringMethod)
    {
        case Filter_Variant::None:
            setNoneFilter();
            break;
        case Filter_Variant::Type:
            setTypeFilter();
            break;

        case Filter_Variant::Producer:
            setProducerFilter();
            break;

        case Filter_Variant::Price:
            setPriceFilter();
            break;
    }
}
