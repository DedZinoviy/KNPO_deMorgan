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

void Test_makeConjunctiveDisjunctiveForm::test_case1()
{

}

QTEST_APPLESS_MAIN(Test_makeConjunctiveDisjunctiveForm)
