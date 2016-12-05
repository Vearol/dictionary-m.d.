#ifndef CURABLEDISEASE_H
#define CURABLEDISEASE_H

#include "Disease.h"
#include <QVector>

class CurableDisease : public Disease
{
public:
    CurableDisease();

    bool getCurability();

private:
    bool curable;
};

#endif // CURABLEDISEASE_H
