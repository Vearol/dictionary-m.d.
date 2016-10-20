#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "DBmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    DBmodel *dbmodel = new DBmodel(qApp);

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("dbmodel", dbmodel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

