#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QVector>
#include "Disease.h"

class Dictionary
{
public:
    Dictionary();

private:
    QVector<Disease> diseases;
};

#endif // DICTIONARY_H
