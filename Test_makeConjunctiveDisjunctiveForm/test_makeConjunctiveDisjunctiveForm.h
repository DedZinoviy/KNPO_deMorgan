#ifndef TEST_MAKECONJUNCTIVEDISJUNCTIVEFORM_H
#define TEST_MAKECONJUNCTIVEDISJUNCTIVEFORM_H
#include <QtTest>
#include <QDomDocument>
#include "../deMorgan/main.h"

// add necessary includes here

class Test_makeConjunctiveDisjunctiveForm : public QObject
{
    Q_OBJECT

public:
    Test_makeConjunctiveDisjunctiveForm();
    ~Test_makeConjunctiveDisjunctiveForm();

private slots:
    void test_case1();

};


#endif // TEST_MAKECONJUNCTIVEDISJUNCTIVEFORM_H
