#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QVector>
#include <QObject>
#include <QString>
#include "Disease.h"

class Dictionary : public QObject
{
    Q_OBJECT
public:
    Dictionary();

    Q_INVOKABLE QString currentProgress();
    void setMessage(const QString &newMessage);
private:
    QString currentMessage;
    QVector<Disease> diseases;
};

#endif // DICTIONARY_H
