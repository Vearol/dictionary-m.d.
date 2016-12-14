#ifndef DISEASE_H
#define DISEASE_H

#include <QString>
#include <QVector>
#include <QSqlTableModel>
#include <QList>
#include "DiseaseData.h"

class Disease
{
public:
    Disease();

    void loadData();
    void setData(QString newName, QString newSymptoms, QString newProcedures, QString newDrugs, int row);

protected:
    QList<DiseaseData> incurable;
    QList<DiseaseData> curable;
};

#endif // DISEASE_H
