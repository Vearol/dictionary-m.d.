#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QVector>
#include <QObject>
#include <QString>
#include "Disease.h"
#include "CustomSqlModel.h"

class Dictionary : public QObject
{
    Q_OBJECT
public:
    Dictionary();

    Q_INVOKABLE QString currentProgress();
    Q_INVOKABLE void addRow(const QString &name, const QString &symptoms, const QString &procedures, const QString &drugs, const QString &table);
    Q_INVOKABLE void removeRow(const QString &name, const QString &table);

    void setModel(CustomSqlModel *model);
    void setMessage(const QString &newMessage);

private:
    QString currentMessage;
    QVector<Disease> diseases;
    CustomSqlModel *m_Model;
};

#endif // DICTIONARY_H
