#include "test_makeDeMorganExpressionOfNegations.h"

test_makeDeMorganExpressionOfNegations::test_makeDeMorganExpressionOfNegations()
{

}

test_makeDeMorganExpressionOfNegations::~test_makeDeMorganExpressionOfNegations()
{

}

bool treeComparison(const QDomNode &firstTree, const QDomNode &secondTree)
{
    QList <QDomNode> firstTreeList;
    QList <QDomNode> secondTreeList;
    treeToList(firstTree, firstTreeList); // Преобразовать первое дерево в список узлов.
    treeToList(secondTree, secondTreeList); // Преобразовать второе дерево в список узлов.

    bool isSameTree = true; // Считать, что изначально деревья одинаковые.
    int firstListLen = firstTreeList.size();
    int secListLen = secondTreeList.size();

    for (int i = 0; i < firstListLen && i < secListLen; i++) // Для каждого элемента первого и второго списков...
    {
        QString firstTreeNodeTag = firstTreeList[i].toElement().tagName();
        QString secTreeNodeTag = secondTreeList[i].toElement().tagName();
        if (firstTreeNodeTag != secTreeNodeTag) // Считать узлы различными, если они имеют различные тэги, не являющийся тэгом операции.
        {
            isSameTree = false;
            return isSameTree;
        }
        else // Иначе...
        {
            if (firstTreeNodeTag == "operation" ) // Проверить узлы на одинаковость значений аттрибута, если они имеют тэг операции.
            {
                QString firstNodeValue = firstTreeList[i].toElement().attributeNode("type").value();
                QString secNodeValue = secondTreeList[i].toElement().attributeNode("type").value();
                if(firstNodeValue != secNodeValue) // Считать узлы операции различными, если значения их аттрибутов не совпадают.
                {
                    isSameTree = false;
                    return isSameTree;
                }
            }
        }
    }
    return isSameTree;
}

void treeToList(const QDomNode & tree, QList <QDomNode> &treeList)
{
    treeList.append(tree); // Добавить текущий узел в список.
    QDomNodeList childList = tree.childNodes(); // Получить дочерние узлы от текущего.
    if (childList.isEmpty()) return; // Если их не существует, то прекратить запись.
    else //Иначе...
    {
        for(int i = 0; i < childList.size(); i++) // Для каждого дочернего узла...
        {
            treeToList(childList.item(i), treeList); // декомпозировать поддерево в список.
        }
    }
}

void test_makeDeMorganExpressionOfNegations::test_case1()
{

}

QTEST_APPLESS_MAIN(test_makeDeMorganExpressionOfNegations)

