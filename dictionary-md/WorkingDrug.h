#ifndef WORKINGDRUG_H
#define WORKINGDRUG_H

#include <QVector>
#include "Medicament.h"

class WorkingDrug : public Medicament
{
public:
    WorkingDrug();

private:
    QVector<QString> sameDrugs;
};

#endif // WORKINGDRUG_H
