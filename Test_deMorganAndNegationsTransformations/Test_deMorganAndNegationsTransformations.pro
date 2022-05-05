QT += testlib
QT -= gui
QT += xml

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
            tst_test_demorganandnegationstransformations.cpp \
            ../deMorgan/deMorganFunctions.cpp

HEADERS += \
    Test_deMorganAndNegationsTransformations.h \
    ../deMorgan/main.h
