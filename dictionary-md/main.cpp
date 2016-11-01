#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QDebug>

#include "CustomSqlModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dictionaryDB");
    db.setUserName("lyubomyr");
    db.setPassword("1");
    bool ok = db.open();
    if(ok != true){
        qDebug() << "Connection: Connection Failed!";
    }
    else{
        qDebug() << "Connection: Connection OK!";
    }

    CustomSqlModel *dbModel = new CustomSqlModel();
    dbModel->setQuery("select * from disease");

    context->setContextProperty("dbmodel", dbModel);

    // db.close();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

