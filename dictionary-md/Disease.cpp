#include "Disease.h"
#include <QDebug>
#include <QSqlRecord>

Disease::Disease()
{
}

void Disease::getData()
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

        diseaseName = name;
        int sympSize = symptomsList.size();
        for (int j = 0; j < sympSize; j++){
            symptoms.push_back(symptomsList[j]);
        }
        int procSize = proceduresList.size();
        for (int j = 0; j < procSize; j++){
            procedures.push_back(proceduresList[j]);
        }
        int drugSize = drugsList.size();
        for (int j = 0; j < drugSize; j++){
            drugs.push_back(drugsList[j]);
        }

        if (drugSize == 0){
            incurable[i].diseaseName = diseaseName;
            incurable[i].symptoms = symptoms;
            incurable[i].procedures = procedures;
        }
        else {
            curable[i].diseaseName = diseaseName;
            curable[i].symptoms = symptoms;
            curable[i].drugs = drugs;
            curable[i].procedures = procedures;
        }
        qDebug() << name;
    }
}

void Disease::setData(QString newName, QString newSymptoms, QString newProcedures, QString newDrugs)
{
    QSqlTableModel model;
    model.setTable("disease");
    model.select();

    int rowCount = model.rowCount();
    incurable.reserve(rowCount);
    curable.reserve(rowCount);

    for (int i = 0; i < rowCount; ++i) {
        QSqlRecord record = model.record(i);
        record.setValue(newName, "name");
        record.setValue(newProcedures, "procedures");
        record.setValue(newSymptoms, "symptoms");
        record.setValue(newDrugs, "drugs");

    }
}
