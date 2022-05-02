QT += testlib
QT -= gui
QT += xml

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_test_makedemorganexpressionofnegations.cpp \
    ../deMorgan/deMorganFunctions.cpp

HEADERS += \
    test_makeDeMorganExpressionOfNegations.h \
    ../deMorgan/main.h
