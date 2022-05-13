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

void Test_isCorrectNode::test_case1()
{

}

QTEST_APPLESS_MAIN(Test_isCorrectNode)

