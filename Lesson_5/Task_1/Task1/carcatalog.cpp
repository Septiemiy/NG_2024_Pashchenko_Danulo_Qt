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

    ui->e_filteringField->setFixedHeight(28);

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
    for(int index = 0; index < m_cars.count(); index++)
    {
        QWidget *carTab = new QWidget();
        QGridLayout *gridLayout = new QGridLayout();

        QLabel *labelProducer = new QLabel("Producer:", carTab);
        gridLayout->addWidget(labelProducer, 0, 0);
        QTextEdit *producerTextEdit = new QTextEdit(m_cars[index].getProducer(), carTab);
        gridLayout->addWidget(producerTextEdit, 0, 1);
        producerTextEdit->setFixedHeight(28);
        producerTextEdit->setReadOnly(true);

        QLabel *labelPrice = new QLabel("Price:", carTab);
        gridLayout->addWidget(labelPrice, 1, 0);
        QTextEdit *priceTextEdit = new QTextEdit(QString::number(m_cars[index].getPrice()), carTab);
        gridLayout->addWidget(priceTextEdit, 1, 1);
        priceTextEdit->setFixedHeight(28);
        priceTextEdit->setReadOnly(true);

        QLabel *labelType = new QLabel("Type", carTab);
        gridLayout->addWidget(labelType, 2, 0);
        QTextEdit *typeTextEdit = new QTextEdit(m_cars[index].getType(), carTab);
        gridLayout->addWidget(typeTextEdit, 2, 1);
        typeTextEdit->setFixedHeight(28);
        typeTextEdit->setReadOnly(true);

        QLabel *labelModelRange = new QLabel("Model range:", carTab);
        gridLayout->addWidget(labelModelRange, 3, 0);
        QTextEdit *modelRangeTextEdit = new QTextEdit(m_cars[index].getModelRange(), carTab);
        gridLayout->addWidget(modelRangeTextEdit, 3, 1);
        modelRangeTextEdit->setFixedHeight(28);
        modelRangeTextEdit->setReadOnly(true);

        QLabel *labelNumberSeats = new QLabel("Number seats:", carTab);
        gridLayout->addWidget(labelNumberSeats, 4, 0);
        QTextEdit *numberSeatsTextEdit = new QTextEdit(QString::number(m_cars[index].getNumberSeats()), carTab);
        gridLayout->addWidget(numberSeatsTextEdit, 4, 1);
        numberSeatsTextEdit->setFixedHeight(28);
        numberSeatsTextEdit->setReadOnly(true);

        QLabel *labelColor = new QLabel("Color:", carTab);
        gridLayout->addWidget(labelColor, 5, 0);
        QTextEdit *colorTextEdit = new QTextEdit(m_cars[index].getColor(), carTab);
        gridLayout->addWidget(colorTextEdit, 5, 1);
        colorTextEdit->setFixedHeight(28);
        colorTextEdit->setReadOnly(true);

        carTab->setLayout(gridLayout);

        ui->tw_cars->addTab(carTab, m_cars[index].getModelRange());
    }
}

void CarCatalog::setFilter(QString filterType)
{
    QString filterText = ui->e_filteringField->toPlainText();
    for(int index = 0; index < m_cars.count(); index++)
    {
        if(filterType == "Producer")
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
        else if(filterType == "Type")
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
        else if(filterType == "Price")
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
        else if(filterType == "None")
        {
            ui->tw_cars->setTabVisible(index, true);
        }
    }
}

void CarCatalog::defineFilteringMethod()
{
    int filteringMethod = ui->cb_filteringOptions->currentIndex();
    switch(filteringMethod)
    {
        case Filter_Variant::None:
            setFilter("None");
            break;

        case Filter_Variant::Type:
            setFilter("Type");
            break;

        case Filter_Variant::Producer:
            setFilter("Producer");
            break;

        case Filter_Variant::Price:
            setFilter("Price");
            break;
    }
}
