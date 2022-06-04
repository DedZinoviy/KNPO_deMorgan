/*!
 * \file
 * \brief The source code file .cpp with the implementation of functions that solve the main problem.
 *
*/
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
    isCorrectNode(node); // Проверить узел на корректность
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
    QDomNode nextNode;
    if (node.toElement().tagName() == "operation") // Если рассмтриваемый узел является узлом операции...
    {
        if (node.toElement().attributeNode("type").value() == "!") // Проверить следующий узел на возможность применения законов, если рассматриваемый узел является отрицанием
        {
            nextNode = node.firstChild();
            if (nextNode.toElement().tagName() == "operation") // Проверить тип операции, если следующий узел является узлом операции.
            {
                QString nextOperationType = nextNode.toElement().attributeNode("type").value(); // Узнать тип операции

                if (nextOperationType == "!") // Если следующий узел является отрицанием, то удалить двойное отрицание
                {
                    QDomNode previousNode = node.parentNode(); // Получить родительский узел первого отрицания
                    QDomNode nextNodeAfter = nextNode.firstChild(); // Получить дочерний узел второго отрицания
                    previousNode.replaceChild(nextNodeAfter, node); // Склеить родительский узел первого отрицания и дочерний узел втрого отрицания
                    deMorganAndNegationTransformations(nextNodeAfter); // Перейти к следующему узлу
                }

                else if (nextOperationType == "&&") // ИначеЕсли следующий узел является конъюнкцией...
                {
                    // Расрксрыть скобки по первому закону де Моргана.
                    QDomNode previousNode = node.parentNode();
                    QDomNode firstNextNode = nextNode.firstChild();
                    QDomNode secNextNode = nextNode.lastChild();
                    QDomNode disjunction = makeDeMorganExpressionOfNegations(firstNextNode, secNextNode, FIRST);

                    previousNode.replaceChild(disjunction, node);

                    QDomNode firstNegation = disjunction.firstChild();
                    QDomNode secNegation = disjunction.lastChild();

                    deMorganAndNegationTransformations(firstNegation);
                    deMorganAndNegationTransformations(secNegation);
                }

                else if (nextOperationType == "||") // ИначеЕсли следующий узел является дизъюнкцией...
                {
                    // Расрксрыть скобки по второму закону де Моргана.
                    QDomNode previousNode = node.parentNode();
                    QDomNode firstNextNode = nextNode.firstChild();
                    QDomNode secNextNode = nextNode.lastChild();
                    QDomNode conjunction = makeDeMorganExpressionOfNegations(firstNextNode, secNextNode, SECOND);

                    previousNode.replaceChild(conjunction, node);

                    QDomNode firstNegation = conjunction.firstChild();
                    QDomNode secNegation = conjunction.lastChild();

                    deMorganAndNegationTransformations(firstNegation);
                    deMorganAndNegationTransformations(secNegation);
                }

                else // Иначе...
                {
                    nextNode = node.firstChild(); //Получить первый дочерний узел операции
                    deMorganAndNegationTransformations(nextNode); // Перейти к первому дочернему узлу рекурсивно
                    nextNode = node.lastChild(); // Получить второй дочерний узел операции
                    deMorganAndNegationTransformations(nextNode); // Перейти ко второму дочернему узлу рекурсивно
                }
            }
        }
        else // Иначе...
        {
            // Перейти к первому дочернему узлу рекурсивно
           QDomNode firstNextNode = node.firstChild();
           deMorganAndNegationTransformations(firstNextNode);

           // Перейти ко второму дочернему узлу рекурсивно
           QDomNode secNextNode = node.lastChild();
           deMorganAndNegationTransformations(secNextNode);
        }
    }
    else if (node.toElement().tagName() == "expression") // ИначеЕсли тэгявляется тэгом выражения...
    {
        // ... Перейти к дочернему узлу
        nextNode = node.firstChild();
        deMorganAndNegationTransformations(nextNode);
    }
}

int errorHandler(int errorCode)
{
    QMap <int, QString> errors;
    errors[1] = "Invalid input file specified. The file may not exist.";
    errors[2] = "Invalid output file specified. The specified location may not exist or may not have write permissions.";
    errors[3] = "Unsupported format. This file is not an .xml file.";
    errors[4] = "There is no parse tree in the specified file, or the parse tree is unreadable in it.";
    errors[5] = "The specified file contains tags that do not belong to valid.";
    errors[6] = "Root node contains more than one child node.";
    errors[7] = "The negation operation has no child operand node.";
    errors[8] = "File contains more than one parse tree.";
    errors[9] = "Binary operations have more than two operands.";
    errors[10] = "Binary operations have a lack of operands.";
    errors[11] = "The negation operation has more than one child node.";
    errors[12] = "The variable has an invalid child tag.";
    errors[13] = "Operation tag is missing a type attribute.";
    errors[14] = "The operation tag is of an invalid type.";
    errors[15] = "";
    errors[16] = "Lack of command line arguments.";
    errors[17] = "The text node is not a child node of the variable";

    std::cout<<errors[errorCode].toStdString()<<std::endl; // Вывести сообщение в зависимости от полученного кода ошибки.
    return errorCode;     // Завершить функцию с полученным кодом ошибки.

}

void isCorrectNode(const QDomNode &node)
{
    QString tagName = node.toElement().tagName(); // Получить тип узла
    // Проверить на ошибки узел, если его тэг - expression
    if (tagName == "expression")
    {
        if (node.childNodes().length() < 1) throw 4; // Сообщить об ошибке, если в узле expression нет дочерних узлов
        if (node.childNodes().length() > 1) throw 6; // Сообщить об ошибке, если в узле expression более одного дочернего узла
        if (!node.parentNode().isNull()) throw 7; // Сообщить об ошибке, если узел  expression не является корневым
        if (node.toElement().elementsByTagName("expression").length() > 0) throw 8; //Сообщить об ошибке, если присутсвует более двух деревьев разбора
        if (node.firstChild().isText()) throw 17; // Сообщить об ошибке, если дочерним узлов является текст
    }

    else if (tagName == "operation") // Проверить на ошибки узел, если его тэг - operation
    {
        if (node.toElement().attributeNode("type").isNull()) throw 13;// Сообщить об ошибке, если узел операции не имееет типа
        QString type = node.toElement().attributeNode("type").value();

        // Проверить на ошибки узлы бинарных операций
        if (type == "&&" || type == "||" || type == "NOR" || type == "XOR" || type == "NAND")
        {
            if (node.childNodes().length() < 2) throw 10; // Сообщить об ошибке, если бинарная операция имеет недостаток операндов
            if (node.childNodes().length() > 2) throw 9; // Сообщить об ошибке, если бинарная операция имеет более двух операндов
            if (node.firstChild().isText() || node.lastChild().isText()) throw 17; // Сообщить об ошибке, если дочерним узлов является текст
        }

        // Проверить на уошибк узел отрицания
        else if (type == "!")
        {
            if (node.childNodes().length() > 1) throw 7; // Сообщить об ошибке, если узел отрицания содержит более одного дочернего узла
            if (node.childNodes().length() < 1) throw 11; // Сообщить об ошибке, если узел отрицания не содержит дочерних узлов
            if (node.firstChild().isText()) throw 17; // Сообщить об ошибке, если дочерним узлов является текст
        }
        else throw 14; // Иначе сообщить, что перация имеет неизвестный тип.
    }

    else if (tagName == "variable")
    {
        // Проверить на ошибки узел переменой
        if (node.childNodes().length() > 1) throw 12; // Сообщить об ошибке, если узел переменной содержит более одного дочернего узла
        if (!node.firstChild().isText()) throw 12; // Сообщить об ошибке, если узел переменной содержит не текстовый дченрий узел
    }
    else if (tagName != "expression" && tagName != "operation" && tagName !="variable" && !node.isText()) // Сообщить об ошибке, если дерево содержит тэги, не принадлежащие к допустимым
    {
        throw 5;
    }
}
