#include "test_isCorrectNode.h"

QDomNode Test_isCorrectNode::getFirstNode(QString inputFileName)
{
    // Получить имя xml файла, в котором требуется найти первый узел
    QDomDocument document(inputFileName);
    QFile inputFile(inputFileName);
    // Открыть указанный файл для работы с ним
    inputFile.open(QIODevice::ReadOnly);
    document.setContent(&inputFile);
    inputFile.close();

    // Получить первый узел дерева разбора.
    QDomElement docNode = document.documentElement();
    return docNode;
}

Test_isCorrectNode::Test_isCorrectNode()
{

}

Test_isCorrectNode::~Test_isCorrectNode()
{

}

void Test_isCorrectNode::twoExpressionTagsInRow()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test1.xml");
        isCorrectNode(source);
    }
    catch (int errorCode)
    {
        QCOMPARE(errorCode, 8);
    }
}

void Test_isCorrectNode::twoChildNodesOfExpression()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test2.xml");
        isCorrectNode(source);
    }
    catch (int errorCode)
    {
        QCOMPARE(errorCode, 6);
    }
}

void Test_isCorrectNode::emptyExpression()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test3.xml");
        isCorrectNode(source);
    }
    catch (int errorCode)
    {
        QCOMPARE(errorCode, 4);
    }
}

void Test_isCorrectNode::notRootExpression()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test4.xml");
        isCorrectNode(source);
    }
    catch (int errorCode)
    {
        QCOMPARE(errorCode, 7);
    }
}


void Test_isCorrectNode::nonDeclaredTags()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test5.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 5);
    }
}

void Test_isCorrectNode::nonDeclaredMixedDeclared()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test6.xml");
        isCorrectNode(source);
        while(source.hasChildNodes())
        {
            isCorrectNode(source.firstChild());
        }
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 5);
    }
}

void Test_isCorrectNode::undeclaredOperationAttribute()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test7.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 13);
    }
}

void Test_isCorrectNode::undeclaredOperationType()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test8.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 14);
    }
}

void Test_isCorrectNode::lackOfDisjunction()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test9.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 10);
    }
}

void Test_isCorrectNode::lackOfNand()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test10.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 10);
    }
}

void Test_isCorrectNode::overageOfConjunction()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test11.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 9);
    }
}

void Test_isCorrectNode::overageOfNor()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test12.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 9);
    }
}

void Test_isCorrectNode::overageOfNegation()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test13.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 7);
    }
}

void Test_isCorrectNode::lackOfNegation()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test14.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 11);
    }
}

void Test_isCorrectNode::notTextInVariable()
{
    try
    {
        QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_isCorrectNode/Tests/test15.xml");
        isCorrectNode(source);
    }
    catch(int errorCode)
    {
        QCOMPARE(errorCode, 12);
    }
}

QTEST_APPLESS_MAIN(Test_isCorrectNode)

