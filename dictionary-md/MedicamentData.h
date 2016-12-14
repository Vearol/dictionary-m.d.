#ifndef MEDICAMENTDATA_H
#define MEDICAMENTDATA_H

#include <QString>

struct MedicamentData
{
public:
    QString drugName;
    double price;
    int amount;
    QString creator;
    QString form;
    double dose;
    int status;
    QString cures;
};

#endif // MEDICAMENTDATA_H
