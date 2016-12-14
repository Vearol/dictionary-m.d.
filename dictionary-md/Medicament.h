#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <QString>
#include <QVector>
#include <QSqlTableModel>
#include <QList>
#include "MedicamentData.h"

class Medicament
{
public:
    Medicament();

    void loadData();
    void setData(QString drugName, double price, int amount, QString creator, QString form, QString newCures, double dose, int row);

    QList<MedicamentData> getWorkingDrugs();
protected:
    QList<MedicamentData> testing;
    QList<MedicamentData> working;
};

#endif // MEDICAMENT_H
