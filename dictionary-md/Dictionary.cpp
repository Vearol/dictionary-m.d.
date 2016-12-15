#include "Dictionary.h"
#include <QDebug>

Dictionary::Dictionary()
{
}

QString Dictionary::currentProgress()
{
    int rows = m_Model->rowCount();
    QString id = QString::number(rows);
    return currentMessage;
}

void Dictionary::addRow(const QString &name, const QString &symptoms,
                        const QString &procedures, const QString &drugs, const QString &table)
{
    int rows = m_Model->rowCount();
    QString id = QString::number(rows);
    QString query = "insert into " + table + " (id, name, symptoms , procedures, drugs) "
                    "values (" + id + ", '" + name + "', '" + symptoms + "', '" + procedures + "', '" + drugs + "');";
    m_Model->setQuery(query);
    m_Model->setQuery("select * from " + table);
}

void Dictionary::removeRow(const QString &name, const QString &table)
{
    QString query = "DELETE FROM " + table + " WHERE name = '" + name + "';";
    m_Model->setQuery(query);
    m_Model->setQuery("select * from " + table);
}

void Dictionary::setModel(CustomSqlModel *model)
{
    m_Model = model;
}

void Dictionary::setMessage(const QString &newMessage)
{
    currentMessage = newMessage;
}

