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

void makeConjunctiveDisjunctiveForm(QDomNode& node)
{
    QDomDocument doc("newForm");
    QDomNode nextNode;
    if (node.toElement().tagName() == "operation") // Если рассматриваемый узел является улом операциии...
    {
        QString operationType = node.toElement().attributeNode("type").value(); // Узнать тип операции

        if (operationType == "NAND" || operationType == "NOR") // Заменить узел на конъюктивно-дизъюнктивную форму, если тип узла NAND или NOR
        {
            QDomNode previousNode = node.parentNode(); // Узнать родительский узел рассматриваемого узла
            QDomNode firstNextNode = node.firstChild(); // Узнать дочерние узлы рассативаемого узла
            QDomNode secNextNode = node.lastChild();

            // Заменить операцию на сочетание отрицания и конъюнкции или дтзъюнкции
            QDomNode negation = doc.createElement("operation"); // Создать операцию отрицания
            negation.toElement().setAttribute("type", "!");

            QDomNode binaryOperation = doc.createElement("operation"); // Создать бинарную операцию в зависимости от исходного узла
            if (operationType == "NAND") // Если исходным узлом был NAND, то создать конъюнкцию
                binaryOperation.toElement().setAttribute("type", "&&");
            else if (operationType == "NOR")
                binaryOperation.toElement().setAttribute("type", "||"); // ИначеЕсли исходным уздом был NOR создать дизъюнкцию

            negation.appendChild(binaryOperation); // Склеить созданные отрицание и бинарную операцию

            binaryOperation.appendChild(firstNextNode); // Склеить с бинарной операцией дочерние узлы исходного узла
            binaryOperation.appendChild(secNextNode);

            previousNode.replaceChild(negation, node); // Слеить родительскй узел исходного узла с получившейся конструкцией

            makeConjunctiveDisjunctiveForm(firstNextNode); // Перейти к следующим дочерним узлам
            makeConjunctiveDisjunctiveForm(secNextNode);
        }
        else if (operationType == "XOR") //ИначеЕсли узел явлется XORом...
        {
            QDomNode previousNode = node.parentNode(); // Узнать родительский узел рассматриваемого узла
            QDomNode firstNextNode = node.firstChild(); // Узнать дочерние узлы рассативаемого узла
            QDomNode secNextNode = node.lastChild();

            // Заменить операцию на сочетание отрицания и конъюнкции или дтзъюнкции
            QDomNode disjunction = doc.createElement("operation"); // Создать операцию дизъюнкции
            disjunction.toElement().setAttribute("type", "||");

            QDomNode firstConjunction = doc.createElement("operation"); // Создать первую операцию конъюнкции
            firstConjunction.toElement().setAttribute("type", "&&");

            QDomNode secondConjunction = doc.createElement("operation"); // Создать вторую операцию конъюнкции
            secondConjunction.toElement().setAttribute("type", "&&");

            QDomNode firstNegation = doc.createElement("operation"); // Создать первую операцию отрицания
            firstNegation.toElement().setAttribute("type", "!");

            QDomNode secondNegation = doc.createElement("operation"); // Создать вторую операцию отрицания
            secondNegation.toElement().setAttribute("type", "!");

            QDomNode doubleFirstNextNode = firstNextNode.cloneNode(); // Получить копии дочерних узлов
            QDomNode doubleSecNextNode = secNextNode.cloneNode();

            firstNegation.appendChild(secNextNode); // Добавить дочерние узлы к первой конъюнкции
            firstConjunction.appendChild(doubleFirstNextNode);
            firstConjunction.appendChild(firstNegation);

            secondNegation.appendChild(firstNextNode); // Добавить дочерние узлы ко второй конъюнкции
            secondConjunction.appendChild(secondNegation);
            secondConjunction.appendChild(doubleSecNextNode);

            //Собрать выражение дизъюнктивное выражение
            disjunction.appendChild(firstConjunction);
            disjunction.appendChild(secondConjunction);

            // Заменить в родительском узле узел на дизъюнктивный
            previousNode.replaceChild(disjunction, node);

            makeConjunctiveDisjunctiveForm(firstConjunction); // Проверить доченрие узлы
            makeConjunctiveDisjunctiveForm(secondConjunction);


        }

        else if (operationType == "&&" || operationType == "||") // иначеЕсли дочерние узлы являются конъюнкцией или дизъюнкцией...
        {
            QDomNode firstNextNode = node.firstChild(); // Получить дочерние узлы
            QDomNode secNextNode = node.lastChild();
            makeConjunctiveDisjunctiveForm(firstNextNode); // Проверить дочерние узлы
            makeConjunctiveDisjunctiveForm(secNextNode);
        }

        else if (operationType == "!") //  иначеЕсли дочерние узел является отрицанием...
        {
            QDomNode firstNextNode = node.firstChild(); // Получить дочерний узел
            makeConjunctiveDisjunctiveForm(firstNextNode); // пеейти к дочернему узлу
        }
    }

    else if (node.toElement().tagName() == "expression") // ИначеЕсли рассматриваемый узел является узлом выражения...
    {
        nextNode = node.firstChild(); // Перейти к дочернему узлу
        makeConjunctiveDisjunctiveForm(nextNode);
    }
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
