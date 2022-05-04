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
    QDomElement docObject = document.documentElement();
    QDomNode docNode = docObject.firstChild();
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

void Test_makeConjunctiveDisjunctiveForm::test_case1()
{

}

QTEST_APPLESS_MAIN(Test_makeConjunctiveDisjunctiveForm)
