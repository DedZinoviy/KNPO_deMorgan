#include "test_makeConjunctiveDisjunctiveForm.h"

Test_makeConjunctiveDisjunctiveForm::Test_makeConjunctiveDisjunctiveForm()
{

}

Test_makeConjunctiveDisjunctiveForm::~Test_makeConjunctiveDisjunctiveForm()
{

}

QDomNode Test_makeConjunctiveDisjunctiveForm::getFirstNode(QString inputFileName)
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

void Test_makeConjunctiveDisjunctiveForm::treeToList(const QDomNode & tree, QList <QDomNode> &treeList)
{
    treeList.append(tree); // Добавить текущий узел в список.
    QDomNodeList childList = tree.childNodes(); // Получить дочерние узлы от текущего.
    for(int i = 0; i < childList.length(); i++) // Для каждого дочернего узла...
    {
        treeToList(childList.item(i), treeList); // декомпозировать поддерево в список.
    }
}

void Test_makeConjunctiveDisjunctiveForm::treeComparison(const QDomNode &firstTree, const QDomNode &secondTree)
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


void Test_makeConjunctiveDisjunctiveForm::emptyTree()
{

    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test1_source.xml");
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test1_etalon.xml");
    try
    {
        makeConjunctiveDisjunctiveForm(source);
    }
    catch(int error)
    {
            treeComparison(source, etalon);
    }
}

void Test_makeConjunctiveDisjunctiveForm::onlyExpressionTag()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test2_source.xml");
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test2_etalon.xml");
    try
    {
        makeConjunctiveDisjunctiveForm(source);
    }
    catch (int error)
    {
        treeComparison(source, etalon);
    }
}

void Test_makeConjunctiveDisjunctiveForm::onlyOneConjunction()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test3_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test3_etalon.xml");
    treeComparison(source, etalon);
}

void Test_makeConjunctiveDisjunctiveForm::combinationOfConjunctionDisjunctionAndNegation()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test4_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test4_etalon.xml");
    treeComparison(source, etalon);
}

void Test_makeConjunctiveDisjunctiveForm::onlyNandOperator()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test5_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test5_etalon.xml");
    treeComparison(source, etalon);
}

void Test_makeConjunctiveDisjunctiveForm::onlyNorOperator()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test6_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test6_etalon.xml");
    treeComparison(source, etalon);
}

void Test_makeConjunctiveDisjunctiveForm::onlyXorOperator()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test7_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test7_etalon.xml");
    treeComparison(source, etalon);
}

void Test_makeConjunctiveDisjunctiveForm::combinationOfNorDisjunctionNegationAndConjunction()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test8_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test8_etalon.xml");
    treeComparison(source, etalon);
}

void Test_makeConjunctiveDisjunctiveForm::norNandCombinationInRow()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test9_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test9_etalon.xml");
    treeComparison(source, etalon);
}

void Test_makeConjunctiveDisjunctiveForm::norNandCombinationInDifferentBranches()
{
    QDomNode source = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test10_source.xml");
    makeConjunctiveDisjunctiveForm(source);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeConjunctiveDisjunctiveForm/Tests/test10_etalon.xml");
    treeComparison(source, etalon);
}

QTEST_APPLESS_MAIN(Test_makeConjunctiveDisjunctiveForm)
