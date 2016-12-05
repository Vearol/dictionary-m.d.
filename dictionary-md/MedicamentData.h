#ifndef MEDICAMENTDATA_H
#define MEDICAMENTDATA_H

#include <QString>

class MedicamentData
{
public:
    MedicamentData();

    QString drugName;
    double price;
    int amount;
    QString creator;
    QString form;
    double dose;
    int status;
};

#endif // MEDICAMENTDATA_H
