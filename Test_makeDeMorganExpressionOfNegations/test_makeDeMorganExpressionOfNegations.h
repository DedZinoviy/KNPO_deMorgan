#ifndef TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
#define TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
#include <QtTest>
#include <QDomDocument>

// add necessary includes here

class test_makeDeMorganExpressionOfNegations : public QObject
{
    Q_OBJECT

public:
    test_makeDeMorganExpressionOfNegations();
    ~test_makeDeMorganExpressionOfNegations();

private slots:
    void test_case1();

};
#endif // TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
