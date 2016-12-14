#include "Disease.h"
#include <QDebug>
#include <QSqlRecord>

Disease::Disease()
{
}

void Disease::loadData()
{
    QSqlTableModel model;
    model.setTable("disease");
    model.select();

    int rowCount = model.rowCount();
    incurable.reserve(rowCount);
    curable.reserve(rowCount);

    for (int i = 0; i < rowCount; ++i) {
        QSqlRecord record = model.record(i);
        QString name = record.value("name").toString();
        QStringList symptomsList = record.value("symptoms").toString().split(",");
        QStringList proceduresList = record.value("procedures").toString().split(",");
        QStringList drugsList = record.value("drugs").toString().split(",");

        int drugSize = drugsList.size();
        int sympSize = symptomsList.size();
        int procSize = proceduresList.size();
        DiseaseData newData;

        if (drugSize > 0){
            newData.diseaseName = name;
            for (int j = 0; j < sympSize; j++){
                newData.symptoms.push_back(symptomsList[j]);
            }
            for (int j = 0; j < procSize; j++){
                newData.procedures.push_back(proceduresList[j]);
            }
            for (int j = 0; j < drugSize; j++){
                newData.drugs.push_back(drugsList[j]);
            }
            curable.push_back(newData);
        }
        else {
            newData.diseaseName = name;
            for (int j = 0; j < sympSize; j++){
                newData.symptoms.push_back(symptomsList[j]);
            }
            for (int j = 0; j < procSize; j++){
                newData.procedures.push_back(proceduresList[j]);
            }
            newData.drugs.clear();
            incurable.push_back(newData);
        }

    }
}

void Disease::setData(QString newName, QString newSymptoms, QString newProcedures, QString newDrugs, int row)
{
    QSqlTableModel model;
    model.setTable("disease");
    model.select();

    int rowCount = model.rowCount();
    incurable.reserve(rowCount);
    curable.reserve(rowCount);

    QSqlRecord record = model.record(row);
    record.setValue(newName, "name");
    record.setValue(newProcedures, "procedures");
    record.setValue(newSymptoms, "symptoms");
    record.setValue(newDrugs, "drugs");
}
