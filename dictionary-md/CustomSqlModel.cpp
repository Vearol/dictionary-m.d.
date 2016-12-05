#include "CustomSqlModel.h"

#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>

CustomSqlModel::CustomSqlModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

void CustomSqlModel::setQuery(const QString &query, const QSqlDatabase &db)
{
    QSqlQueryModel::setQuery(query, db);
    generateRoleNames();
}

void CustomSqlModel::setQuery(const QSqlQuery & query)
{
    QSqlQueryModel::setQuery(query);
    generateRoleNames();
}

void CustomSqlModel::generateRoleNames()
{
    m_roleNames.clear();
    for(int i = 0; i < record().count(); i ++) {
        m_roleNames.insert(Qt::UserRole + i + 1, record().fieldName(i).toUtf8());
    }
}

QVariant CustomSqlModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    if(role < Qt::UserRole) {
        value = QSqlQueryModel::data(index, role);
    }
    else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}
