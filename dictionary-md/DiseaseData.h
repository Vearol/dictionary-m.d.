#ifndef DISEASEDATA_H
#define DISEASEDATA_H

#include <QString>
#include <QVector>

class DiseaseData
{
public:
    DiseaseData();

    QString diseaseName;
    QVector<QString> symptoms;
    QVector<QString> procedures;
    QVector<QString> drugs;
};

#endif // DISEASEDATA_H
