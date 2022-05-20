#ifndef TEST_ERRORHANDLER_H
#define TEST_ERRORHANDLER_H
#include "../deMorgan/main.h"

#include <QtTest>

// add necessary includes here

class Test_errorHandler : public QObject
{
    Q_OBJECT

public:
    Test_errorHandler();
    ~Test_errorHandler();

private slots:
    void test_case1();

};

#endif // TEST_ERRORHANDLER_H
