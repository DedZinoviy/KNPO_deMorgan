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

void test_deMorganAndNegationsTransformations::treeComparison(const QDomNode &firstTree, const QDomNode &secondTree)
{

    QList <QDomNode> firstTreeList;
    QList <QDomNode> secondTreeList;
    treeToList(firstTree, firstTreeList); // Преобразовать первое дерево в список узлов.
    treeToList(secondTree, secondTreeList); // Преобразовать второе дерево в список узлов.

    int firstListLen = firstTreeList.size();
    int secListLen = secondTreeList.size();


    for (int i = 0; i < firstListLen && i < secListLen; i++) // Для каждого элемента первого и второго списков...
    {

        QString firstTreeNodeTag = firstTreeList[i].toElement().tagName();
        QString secTreeNodeTag = secondTreeList[i].toElement().tagName();


        QCOMPARE(firstTreeNodeTag, secTreeNodeTag); // Сравнить имена тэговы

            if (firstTreeNodeTag == "operation" ) // Проверить узлы на одинаковость значений аттрибута, если они имеют тэг операции.
            {
                QString firstNodeValue = firstTreeList[i].toElement().attributeNode("type").value();
                QString secNodeValue = secondTreeList[i].toElement().attributeNode("type").value();

                if(firstNodeValue != secNodeValue) // Считать узлы операции различными, если значения их аттрибутов не совпадают.
                {
                    QCOMPARE(firstNodeValue, secNodeValue);
                }
            }
    }
}
void test_deMorganAndNegationsTransformations::test_case1()
{

}

QTEST_APPLESS_MAIN(test_deMorganAndNegationsTransformations)

