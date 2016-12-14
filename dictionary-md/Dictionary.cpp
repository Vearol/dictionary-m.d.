#include "Dictionary.h"

Dictionary::Dictionary()
{
}

QString Dictionary::currentProgress()
{
    return currentMessage;
}

void Dictionary::setMessage(const QString &newMessage)
{
    currentMessage = newMessage;
}

