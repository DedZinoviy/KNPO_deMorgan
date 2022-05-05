#ifndef TEST_DEMORGANANDNEGATIONSTRANSFORMATIONS_H
#define TEST_DEMORGANANDNEGATIONSTRANSFORMATIONS_H
#include "../deMorgan/main.h"
#include <QtTest>

// add necessary includes here

class test_deMorganAndNegationsTransformations : public QObject
{
    Q_OBJECT

public:
    test_deMorganAndNegationsTransformations();
    ~test_deMorganAndNegationsTransformations();

private slots:
    void test_case1();

};
#endif // TEST_DEMORGANANDNEGATIONSTRANSFORMATIONS_H
