#ifndef DISEASE_H
#define DISEASE_H

#include <QString>
#include <QVector>
#include <QSqlTableModel>
#include <QList>

class Disease
{
public:
    Disease();

    void getData();
    void setData(QString newName, QString newSymptoms, QString newProcedures, QString newDrugs);

private:
    QString diseaseName;
    QVector<QString> symptoms;
    QVector<QString> procedures;
    QVector<QString> drugs;

    QSqlTableModel diseaseTable;

protected:
    QList<Disease> incurable;
    QList<Disease> curable;
};

#endif // DISEASE_H
