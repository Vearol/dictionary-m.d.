#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>

#include "CustomSqlModel.h"
#include "Disease.h"
#include "Dictionary.h"
#include "Medicament.h"
#include "Drugstore.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Dictionary dict;

    QQmlContext *context = engine.rootContext();

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("dictionaryDB");
    db.setUserName("lyubomyr");
    db.setPassword("1");
    bool ok = db.open();
    if (ok != true){
   //     qDebug() << "Connection: Connection Failed!";
        dict.setMessage("Connection: Connection Failed!");
    }
    else {
   //     qDebug() << "Connection: Connection OK!";
        dict.setMessage("Connection: Connection OK!");
    }

    CustomSqlModel *diseaseModel = new CustomSqlModel();
    diseaseModel->setQuery("select * from disease");
    CustomSqlModel *drugModel = new CustomSqlModel();
    drugModel->setQuery("select * from medicament");

    dict.setModel(diseaseModel);

    Disease disease;
    disease.loadData();

    Medicament drugs;
    drugs.loadData();

    Drugstore store;
    store.bestWorkingDrug.setDrugList(drugs.getWorkingDrugs());

    context->setContextProperty("diseaseModel", diseaseModel);
    context->setContextProperty("drugModel", drugModel);
    context->setContextProperty("drugStore", &store);
    context->setContextProperty("dict", &dict);


    //QSqlQuery a;
    // db.close();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

