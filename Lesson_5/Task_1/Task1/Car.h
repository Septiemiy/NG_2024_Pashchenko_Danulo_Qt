#ifndef CAR_H
#define CAR_H

#include "CarParent.h"

class Car : public CarParent
{
private:
    QString m_model_range;
    int m_number_seats;
    QString m_color;

public:
    Car() {}
    ~Car() {}

    void setModelRange(QString model_range) { m_model_range = model_range; }
    void setNumberSeats(int number_seats) { m_number_seats = number_seats; }
    void setColor(QString color) { m_color = color; }
    void setPrice(int price) { m_price = price; }
    void setType(QString type) { m_type = type; }
    QString getModelRange() { return m_model_range; }
    int getNumberSeats() { return m_number_seats; }
    QString getColor() { return m_color; }
    int getPrice() { return m_price; }
    QString getType() { return m_type; }
};

#endif // CAR_H
