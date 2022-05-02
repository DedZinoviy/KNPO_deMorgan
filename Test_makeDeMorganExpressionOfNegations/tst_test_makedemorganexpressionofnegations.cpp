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

QDomNode getFirstNode(QString inputFileName)
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
    QDomDocument doc("");
    QDomElement A = doc.createElement("variable");
    A.appendChild(doc.createTextNode("A"));
    QDomElement B = doc.createElement("variable");
    B.appendChild(doc.createTextNode("B"));
    QDomNode result = makeDeMorganExpressionOfNegations(A, B, FIRST);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test1_etalon.xml");
    bool comp = treeComparison(result, etalon);
    QCOMPARE(comp, true);
}

void test_makeDeMorganExpressionOfNegations::makeConjunctionOfNegations()
{
    QDomDocument doc("");
    QDomElement A = doc.createElement("variable");
    A.appendChild(doc.createTextNode("A"));
    QDomElement B = doc.createElement("variable");
    B.appendChild(doc.createTextNode("B"));
    QDomNode result = makeDeMorganExpressionOfNegations(A, B, SECOND);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test2_etalon.xml");
    bool comp = treeComparison(result, etalon);
    QCOMPARE(comp, true);
}

void test_makeDeMorganExpressionOfNegations::makeDisjunctionOfNegationsWithComplexExpressions()
{
    QDomDocument doc("");
    QDomElement disjunction = doc.createElement("operation");
    disjunction.setAttribute("type", "||");
    QDomElement A = doc.createElement("variable");
    A.appendChild(doc.createTextNode("A"));
    QDomElement B = doc.createElement("variable");
    B.appendChild(doc.createTextNode("B"));
    disjunction.appendChild(A);
    disjunction.appendChild(B);

    QDomElement conjunction = doc.createElement("operation");
    conjunction.setAttribute("type", "&&");
    QDomElement C = doc.createElement("variable");
    A.appendChild(doc.createTextNode("C"));
    QDomElement D = doc.createElement("variable");
    B.appendChild(doc.createTextNode("D"));
    conjunction.appendChild(C);
    conjunction.appendChild(D);

    QDomNode result = makeDeMorganExpressionOfNegations(disjunction, conjunction, FIRST);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test3_etalon.xml");
    bool comp = treeComparison(result, etalon);
    QCOMPARE(comp, true);

}

void test_makeDeMorganExpressionOfNegations::makeConjunctionOfNegationsWithComplexExpressions()
{
    QDomDocument doc("");
    QDomElement disjunction = doc.createElement("operation");
    disjunction.setAttribute("type", "||");
    QDomElement A = doc.createElement("variable");
    A.appendChild(doc.createTextNode("A"));
    QDomElement B = doc.createElement("variable");
    B.appendChild(doc.createTextNode("B"));
    disjunction.appendChild(A);
    disjunction.appendChild(B);

    QDomElement conjunction = doc.createElement("operation");
    conjunction.setAttribute("type", "&&");
    QDomElement C = doc.createElement("variable");
    A.appendChild(doc.createTextNode("C"));
    QDomElement D = doc.createElement("variable");
    B.appendChild(doc.createTextNode("D"));
    conjunction.appendChild(C);
    conjunction.appendChild(D);

    QDomNode result = makeDeMorganExpressionOfNegations(disjunction, conjunction, SECOND);
    QDomNode etalon = getFirstNode("../../KNPO_deMorgan/Test_makeDeMorganExpressionOfNegations/Tests/test4_etalon.xml");
    bool comp = treeComparison(result, etalon);
    QCOMPARE(comp, true);
}

QTEST_APPLESS_MAIN(test_makeDeMorganExpressionOfNegations)

