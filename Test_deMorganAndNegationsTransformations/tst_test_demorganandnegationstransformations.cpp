#include "Test_deMorganAndNegationsTransformations.h"

test_deMorganAndNegationsTransformations::test_deMorganAndNegationsTransformations()
{

}

test_deMorganAndNegationsTransformations::~test_deMorganAndNegationsTransformations()
{

}

QDomNode test_deMorganAndNegationsTransformations::getFirstNode(QString inputFileName)
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

void test_deMorganAndNegationsTransformations::treeToList(const QDomNode & tree, QList <QDomNode> &treeList)
{
    treeList.append(tree); // Добавить текущий узел в список.
    QDomNodeList childList = tree.childNodes(); // Получить дочерние узлы от текущего.
    for(int i = 0; i < childList.length(); i++) // Для каждого дочернего узла...
    {
        treeToList(childList.item(i), treeList); // декомпозировать поддерево в список.
    }
}
void test_deMorganAndNegationsTransformations::test_case1()
{

}

QTEST_APPLESS_MAIN(test_deMorganAndNegationsTransformations)

