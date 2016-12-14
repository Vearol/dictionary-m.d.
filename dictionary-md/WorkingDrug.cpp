#include "WorkingDrug.h"
#include <QDebug>

QString cutEmptySpace(const QString &input){
    QString newString = input;
    int size = input.size(), i = 0;
    for (; i < size; i++){
        if (newString[i] == ' ')
            break;
    }
    newString.chop(size - i);
    return newString;
}

WorkingDrug::WorkingDrug()
{
}

void WorkingDrug::setDrugList(const QList<MedicamentData> &newList)
{
    working = newList;
}

QVector<MedicamentData> WorkingDrug::getDrugsForDisease(const QString &diseaseName)
{
    int size = working.size();
    QVector<MedicamentData> needed;
    QString drug, disease;
    needed.reserve(size);
    for (int i = 0; i < size; i++){
        drug = cutEmptySpace(working[i].cures);
        disease = cutEmptySpace(diseaseName);
        if (drug == disease){
            needed.push_back(working[i]);
        }
    }
    return needed;
}

