#ifndef TESTDRUG_H
#define TESTDRUG_H

#include <QVector>
#include "Medicament.h"

class TestDrug : public Medicament
{
public:
    TestDrug();

private:
    int chanseOfSucseed;
};

#endif // TESTDRUG_H
