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

void test_deMorganAndNegationsTransformations::emptyTree()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test1_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test1_etalon.xml");
    treeComparison(source, etalon);

}

void test_deMorganAndNegationsTransformations::onlyExpressionTag()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test2_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test2_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::onlyOneNegation()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test3_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test3_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::doubleNegation()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test4_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test4_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::negationOfDoubleNegation()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test5_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test5_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::twoDoubleNegationsAtRow()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test6_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test6_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::twoNegationsInDifferentBranches()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test7_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test7_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::noSuitableSituations()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test8_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test8_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::oneFirstDeMorganSituation()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test9_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test9_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::oneSecondDeMorganSituation()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test10_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test10_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::twoFirstDeMorganSituationsInRow()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test11_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test11_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::twoFirstDemorganSituationsInDifferentBranches()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test12_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test12_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::twoSecondDeMorganSituationsInRow()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test13_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test13_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::twoSecondDeMorganSituationsInDifferentBranches()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test14_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test14_etalon.xml");
    treeComparison(source, etalon);
}


void test_deMorganAndNegationsTransformations::combinationOfDoubleNegationAndFirstDeMorganInRow()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test15_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test15_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::combinationOfDoubleNegationAndSecondDeMorganInRow()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test16_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test16_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::combinationOfDoubleNegationAndFirstDeMorganInDifferentBranches()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test17_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test17_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::combinationOfDoubleNegationAndSecondDeMorganInDifferentBranches()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test18_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test18_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::combinationOfSecondDeMorganAndFirstDeMorganInRow()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test19_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test19_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::combinationOfSecondDeMorganAndSecondDeMorganInDifferentBranches()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test20_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test20_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::negationOfFirstDeMorgan()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test21_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test21_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::negationOfSecondDeMorgan()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test22_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test22_etalon.xml");
    treeComparison(source, etalon);
}

void test_deMorganAndNegationsTransformations::complexTest()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test23_source.xml");
    deMorganAndNegationTransformations(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_deMorganAndNegationsTransformations/Tests/test23_etalon.xml");
    treeComparison(source, etalon);
}

QTEST_APPLESS_MAIN(test_deMorganAndNegationsTransformations)

