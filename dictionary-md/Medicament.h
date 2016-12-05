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

    void getData();
    void setData(QString drugName, double price, int amount, QString creator, QString form, double dose, int row);

protected:
    QList<MedicamentData> testing;
    QList<MedicamentData> working;
};

#endif // MEDICAMENT_H
