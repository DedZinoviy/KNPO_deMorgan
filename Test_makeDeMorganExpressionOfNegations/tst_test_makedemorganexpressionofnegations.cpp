#include "test_makeDeMorganExpressionOfNegations.h"

test_makeDeMorganExpressionOfNegations::test_makeDeMorganExpressionOfNegations()
{

}

test_makeDeMorganExpressionOfNegations::~test_makeDeMorganExpressionOfNegations()
{

}

void test_makeDeMorganExpressionOfNegations::treeComparison(const QDomNode &firstTree, const QDomNode &secondTree)
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

void test_makeDeMorganExpressionOfNegations::treeToList(const QDomNode & tree, QList <QDomNode> &treeList)
{
    treeList.append(tree); // Добавить текущий узел в список.
    QDomNodeList childList = tree.childNodes(); // Получить дочерние узлы от текущего.
    for(int i = 0; i < childList.length(); i++) // Для каждого дочернего узла...
    {
        treeToList(childList.item(i), treeList); // декомпозировать поддерево в список.
    }
}

QDomNode test_makeDeMorganExpressionOfNegations::getFirstNode(QString inputFileName)
{
    // Получить имя xml файла, в котором требуется найти первый узел
    QDomDocument document(inputFileName);
    QFile inputFile(inputFileName);
    // Открыть указанный файл для работы с ним
    inputFile.open(QIODevice::ReadOnly);
    document.setContent(&inputFile);
    inputFile.close();

    // Получить первый узел дерева разбора.
    QDomElement docObject = document.documentElement();
    QDomNode docNode = docObject.firstChild();
    return docNode;
}

void test_makeDeMorganExpressionOfNegations::makeDisjunctionOfNegations()
{
    QDomNode A = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test1_source1.xml");
    QDomNode B = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test1_source2.xml");
    QDomNode result = makeDeMorganExpressionOfNegations(A, B, FIRST);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test1_etalon.xml");
    treeComparison(result, etalon);
}

void test_makeDeMorganExpressionOfNegations::makeConjunctionOfNegations()
{
    QDomNode A = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test2_source1.xml");
    QDomNode B = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test2_source2.xml");
    QDomNode result = makeDeMorganExpressionOfNegations(A, B, SECOND);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test2_etalon.xml");
    treeComparison(result, etalon);
}

void test_makeDeMorganExpressionOfNegations::makeDisjunctionOfNegationsWithComplexExpressions()
{
    QDomNode disjunction = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test3_source1.xml");
    QDomNode conjunction = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test3_source2.xml");

    QDomNode result = makeDeMorganExpressionOfNegations(disjunction, conjunction, FIRST);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test3_etalon.xml");
    treeComparison(result, etalon);
}

void test_makeDeMorganExpressionOfNegations::makeConjunctionOfNegationsWithComplexExpressions()
{
    QDomNode disjunction = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test4_source1.xml");
    QDomNode conjunction = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test4_source2.xml");

    QDomNode result = makeDeMorganExpressionOfNegations(disjunction, conjunction, SECOND);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test4_etalon.xml");
    treeComparison(result, etalon);
}

QTEST_APPLESS_MAIN(test_makeDeMorganExpressionOfNegations)

