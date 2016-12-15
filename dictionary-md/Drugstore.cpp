#include "Drugstore.h"
#include <QDebug>

Drugstore::Drugstore()
{
}

QString cutEmptySpace1(const QString &input){
    QString newString = input;
    int size = input.size(), i = 0;
    for (; i < size; i++){
        if (newString[i] == ' ')
            break;
    }
    newString.chop(size - i);
    return newString;
}

void Drugstore::formResipe(const QString &diseaseName)
{
    neededDrugs = bestWorkingDrug.getDrugsForDisease(diseaseName);
    int size = neededDrugs.size();
    double minPrice = neededDrugs[0].price;
    for (int i = 0; i < size; i++){
        if (neededDrugs[i].price <= minPrice){
            bestWorkingDrug.bestDrug.drugName = neededDrugs[i].drugName;
            bestWorkingDrug.bestDrug.amount = neededDrugs[i].amount;
            bestWorkingDrug.bestDrug.creator = neededDrugs[i].creator;
            bestWorkingDrug.bestDrug.cures = neededDrugs[i].cures;
            bestWorkingDrug.bestDrug.dose = neededDrugs[i].dose;
            bestWorkingDrug.bestDrug.form = neededDrugs[i].form;
            bestWorkingDrug.bestDrug.price = neededDrugs[i].price;
        }
    }
}

double Drugstore::getBestPrice()
{
    return bestWorkingDrug.bestDrug.price;
}

double Drugstore::getBestDose()
{
    return bestWorkingDrug.bestDrug.dose;
}

double Drugstore::getBestAmount()
{
    return bestWorkingDrug.bestDrug.amount;
}

QString Drugstore::getBestName()
{
    return bestWorkingDrug.bestDrug.drugName;
}

QString Drugstore::getBestCreator()
{
    return bestWorkingDrug.bestDrug.creator;
}

QString Drugstore::getBestForm()
{
    return bestWorkingDrug.bestDrug.form;
}

QString Drugstore::restDrugs()
{
    int size = neededDrugs.size();
    if (size == 1){
        return "";
    } else{
        QString result = "Also you can use: \n";
        for (int i = 0; i < size; i++){
            if (neededDrugs[i].price != bestWorkingDrug.bestDrug.price){
                QString price = QString::number(neededDrugs[i].price);
                result += cutEmptySpace1(neededDrugs[i].drugName) + " for " + price +"$"+ "\n";
            }
        }
        return result;
    }
}

