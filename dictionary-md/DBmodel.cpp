#include "DBmodel.h"

DBmodel::DBmodel(QObject *parent) : QSqlQueryModel(parent)
{
    int idx = 0;
    QHash<int, QByteArray> roleNames;
    while( COLUMN_NAMES[idx]) {
        roleNames[Qt::UserRole + idx + 1] = COLUMN_NAMES[idx];
        idx++;
    }
    setRoleNames(roleNames);
    refresh();
}

QVariant DBmodel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if(role < Qt::UserRole)
    {
        value = QSqlQueryModel::data(index, role);
    }
    else
    {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}

void DBmodel::refresh()
{
    this->setQuery(SQL_SELECT);
}

const char* DBmodel::COLUMN_NAMES[] = {
    "id",
    "symptoms",
    "procedures",
    "drugs",
    NULL
};
const char* DBmodel::SQL_SELECT =
    "SELECT disease.id, disease.symptoms, disease.procedures, disease.drugs";

