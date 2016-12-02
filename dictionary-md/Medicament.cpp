#include "Medicament.h"

Medicament::Medicament()
{
}

void Medicament::getData()
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
        double priceN = record.value("price").toDouble();
        double doseN = record.value("dose").toDouble();
        double amountN = record.value("amount").toInt();
        double statusN = record.value("status").toInt();

        if (statusN == 0){
            testing[i].drugName = nameN;
            testing[i].creator = creatorN;
            testing[i].amount = amountN;
            testing[i].form = formN;
            testing[i].dose = doseN;
            testing[i].price = priceN;
        }
        else {
            working[i].drugName = nameN;
            working[i].creator = creatorN;
            working[i].amount = amountN;
            working[i].form = formN;
            working[i].dose = doseN;
            working[i].price = priceN;
        }
}

void Medicament::setData(QString newDrugName, double newPrice, int newAmount, QString newCreator, QString newForm, double newDose)
{
    QSqlTableModel model;
    model.setTable("medicament");
    model.select();

    int rowCount = model.rowCount();
    incurable.reserve(rowCount);
    curable.reserve(rowCount);

    for (int i = 0; i < rowCount; ++i) {
        QSqlRecord record = model.record(i);
        record.setValue(newDrugName, "name");
        record.setValue(newPrice, "price");
        record.setValue(newAmount, "amount");
        record.setValue(newForm, "form");
        record.setValue(newDose, "dose");

    }
}

