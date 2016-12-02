#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <QString>
#include <QVector>
#include <QSqlTableModel>
#include <QList>

class Medicament
{
public:
    Medicament();

    void getData();
    void setData(QString drugName, double price, int amount, QString creator,QString form, double dose);

private:
    QString drugName;
    double price;
    int amount;
    QString creator;
    QString form;
    double dose;
    int status;

protected:
    QList<Medicament> testing;
    QList<Medicament> working;
};

#endif // MEDICAMENT_H
