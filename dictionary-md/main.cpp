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
#include "Medicament.h"

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
    if (ok != true){
        qDebug() << "Connection: Connection Failed!";
    }
    else {
        qDebug() << "Connection: Connection OK!";
    }

    CustomSqlModel *diseaseModel = new CustomSqlModel();
    diseaseModel->setQuery("select * from disease");
    CustomSqlModel *drugModel = new CustomSqlModel();
    drugModel->setQuery("select * from medicament");

    Disease disease;
    disease.getData();

   // Medicament drug;
   // drug.getData();

    context->setContextProperty("diseaseModel", diseaseModel);
    context->setContextProperty("drugModel", drugModel);

    //QSqlQuery a;
    // db.close();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

