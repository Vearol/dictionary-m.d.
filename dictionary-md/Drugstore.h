#ifndef DRUGSTORE_H
#define DRUGSTORE_H

#include <QString>
#include <QVector>
#include <QObject>
#include "WorkingDrug.h"
#include "TestDrug.h"

class Drugstore : public QObject{
    Q_OBJECT

public:
    Drugstore();

    Q_INVOKABLE void formResipe(const QString &diseaseName);
    Q_INVOKABLE double getBestPrice();
    Q_INVOKABLE double getBestDose();
    Q_INVOKABLE double getBestAmount();
    Q_INVOKABLE QString getBestName();
    Q_INVOKABLE QString getBestCreator();
    Q_INVOKABLE QString getBestForm();
    
    Q_INVOKABLE QString restDrugs();

    WorkingDrug bestWorkingDrug;

private:
    QVector<MedicamentData> neededDrugs;
    QVector<MedicamentData> hopingDrugs;
};

#endif // DRUGSTORE_H
