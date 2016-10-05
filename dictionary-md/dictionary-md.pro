TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Disease.cpp \
    Drugstore.cpp \
    Medicament.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Disease.h \
    Drugstore.h \
    Medicament.h

