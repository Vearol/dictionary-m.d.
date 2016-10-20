#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <QString>
#include <QVector>

class Medicament
{
public:
    Medicament();

private:
    QString drugName;
    double price;
    int amount;
    QString creator;
    QString form;
    double dose;
};

#endif // MEDICAMENT_H
