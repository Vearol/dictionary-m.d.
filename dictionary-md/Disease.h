#ifndef DISEASE_H
#define DISEASE_H

#include <QString>
#include <QVector>

class Disease
{
public:
    Disease();
private:
    QString diseaseName;
    QVector<QString> symptoms;
    QVector<QString> procedures;
    QVector<QString> drugs;
};

#endif // DISEASE_H
