#ifndef CARPARENT_H
#define CARPARENT_H

#include "QString"

class CarParent
{
public:
    CarParent() {}
    ~CarParent() {}

    void setProducer(QString producer) {m_producer = producer; }
    QString getProducer() { return m_producer; }

protected:
    int m_price;
    QString m_type;

private:
    QString m_producer;
};

#endif // CARPARENT_H
