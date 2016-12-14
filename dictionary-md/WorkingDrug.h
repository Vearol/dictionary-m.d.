#ifndef WORKINGDRUG_H
#define WORKINGDRUG_H

#include <QVector>
#include <QList>
#include "Medicament.h"
#include "MedicamentData.h"

class WorkingDrug : public Medicament
{
public:
    WorkingDrug();
    MedicamentData bestDrug;
    void setDrugList(const QList<MedicamentData> &newList);

    QVector<MedicamentData> getDrugsForDisease(const QString &diseaseName);
};

#endif // WORKINGDRUG_H
