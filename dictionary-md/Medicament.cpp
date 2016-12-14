#include "Medicament.h"
#include <QSqlRecord>
#include <QDebug>

Medicament::Medicament()
{
}

void Medicament::loadData()
{
    QSqlTableModel model;
    model.setTable("medicament");
    model.select();

    int rowCount = model.rowCount();
    working.reserve(rowCount);
    testing.reserve(rowCount);

    for (int i = 0; i < rowCount; ++i) {
        QSqlRecord record = model.record(i);
        QString nameN = record.value("name").toString();
        QString creatorN = record.value("creator").toString();
        QString formN = record.value("form").toString();
        QString curesN = record.value("cures").toString();
        double priceN = record.value("price").toDouble();
        double doseN = record.value("dose").toDouble();
        double amountN = record.value("amount").toInt();
        double statusN = record.value("status").toInt();
        MedicamentData newData;
        if (statusN == 0){
            newData.drugName = nameN;
            newData.creator = creatorN;
            newData.amount = amountN;
            newData.form = formN;
            newData.dose = doseN;
            newData.price = priceN;
            newData.cures = curesN;
            testing.push_back(newData);
        }
        else {
            newData.drugName = nameN;
            newData.creator = creatorN;
            newData.amount = amountN;
            newData.form = formN;
            newData.dose = doseN;
            newData.price = priceN;
            newData.cures = curesN;
            working.push_back(newData);
        }
    }
}

void Medicament::setData(QString newDrugName, double newPrice, int newAmount, QString newCreator, QString newForm, QString newCures, double newDose, int row)
{
    QSqlTableModel model;
    model.setTable("medicament");
    model.select();

    QSqlRecord record = model.record(row);
    record.setValue(newDrugName, "name");
    record.setValue(newPrice, "price");
    record.setValue(newAmount, "amount");
    record.setValue(newForm, "form");
    record.setValue(newCreator, "creator");
    record.setValue(newDose, "dose");
    record.setValue(newCures, "cures");
}

QList<MedicamentData> Medicament::getWorkingDrugs()
{
    return working;
}

