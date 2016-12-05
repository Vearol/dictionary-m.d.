TEMPLATE = app

QT += qml quick
QT += sql
CONFIG += c++11

SOURCES += main.cpp \
    Disease.cpp \
    Drugstore.cpp \
    Medicament.cpp \
    IncurableDisease.cpp \
    CurableDisease.cpp \
    Dictionary.cpp \
    TestDrug.cpp \
    WorkingDrug.cpp \
    CustomSqlModel.cpp \
    DiseaseData.cpp \
    MedicamentData.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Disease.h \
    Drugstore.h \
    Medicament.h \
    IncurableDisease.h \
    CurableDisease.h \
    Dictionary.h \
    TestDrug.h \
    WorkingDrug.h \
    CustomSqlModel.h \
    DiseaseData.h \
    MedicamentData.h

