#include <QtTest>

// add necessary includes here

class Test_deMorgan : public QObject
{
    Q_OBJECT

public:
    Test_deMorgan();
    ~Test_deMorgan();

private slots:
    void test_case1();

};


Test_deMorgan::Test_deMorgan()
{

}

Test_deMorgan::~Test_deMorgan()
{

}

void Test_deMorgan::test_case1()
{

}

QTEST_APPLESS_MAIN(Test_deMorgan)

#include "tst_test_demorgan.moc"
