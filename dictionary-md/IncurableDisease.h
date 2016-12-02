#ifndef INCURABLEDISEASE_H
#define INCURABLEDISEASE_H

#include <QVector>
#include "Disease.h"

class IncurableDisease : public Disease
{
public:
    IncurableDisease();

    bool getCurability();

    QVector<Disease> incurableList;

private:
    bool curable;
};

#endif // INCURABLEDISEASE_H
