#ifndef INCURABLEDISEASE_H
#define INCURABLEDISEASE_H

#include <QVector>
#include "Disease.h"

class IncurableDisease : public Disease
{
public:
    IncurableDisease();

    bool getCurability();

private:
    bool curable;
};

#endif // INCURABLEDISEASE_H
