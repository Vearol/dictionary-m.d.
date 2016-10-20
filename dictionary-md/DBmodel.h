#ifndef DBMODEL_H
#define DBMODEL_H

#include <QObject>
#include <QtSql/qsqlquerymodel.h>

class DBmodel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit DBmodel(QObject *parent);
    void refresh();
    QVariant data(const QModelIndex &index, int role) const;

private:
    const static char* COLUMN_NAMES[];
    const static char* SQL_SELECT;
};

#endif // DBMODEL_H
