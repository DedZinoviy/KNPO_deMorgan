#include "main.h"


QDomNode makeDeMorganExpressionOfNegations(QDomNode &firstChild, QDomNode &secondChild, DeMorganLaws type)
{
    QDomDocument doc("DeMorgan");

        // Создать бинарную операцию согласно указанному закону Де Моргана
        QDomElement operation = doc.createElement("operation");

        switch (type)
        {
        case FIRST:  // создать дизъюнкцию, если указан первый закон
            operation.setAttribute("type", "||");
            break;
        case SECOND: // Создать конъюнкцию, если указан второй закон
            operation.setAttribute("type", "&&");
            break;
        }

        // Создать отрицание первого операнда
        QDomElement firstNegation = doc.createElement("operation");
        firstNegation.setAttribute("type", "!");
        firstNegation.appendChild(firstChild);

        // создать отрицание второго операнда
        QDomElement secondNegation = doc.createElement("operation");
        secondNegation.setAttribute("type", "!");
        secondNegation.appendChild(secondChild);

        // Добавить созданные отрицания операндов как дочерние узлы к операции
        operation.appendChild(firstNegation);
        operation.appendChild(secondNegation);

        return operation;
}

void makeConjunctiveDisjunctiveForm(QDomNode & node)
{

}

void deMorganAndNegationTransformations(QDomNode& node)
{

}

int errorHandler(int errorCode)
{
    return 0;
}

int isCorrectNode(const QDomNode &node)
{
    return 0;
}
