#ifndef DRUGSTORE_H
#define DRUGSTORE_H

#include <QString>
#include <QVector>
#include "Medicament.h"

class Drugstore
{
public:
    Drugstore();

private:
    QVector<Medicament> drugs;
};

#endif // DRUGSTORE_H
