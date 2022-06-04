/*!
 * \file
 * \brief The source code file .cpp with the implementation of the main function.
 *
*/
#include <QCoreApplication>
#include "main.h"

/*!
 * \brief main - the main function of program.
 * \param argc[in] - number of arguments.
 * \param argv[in] - arguments of command line.
 * \return error code, 0 if there are no errors.
 */
int main(int argc, char *argv[])
{
    try
    {
        if (argc < 3) throw 16; // Сообщить об ошибке, если не хватает аргкментов при запуске программы.

        // Начать работу с указанными файлами
        FileWork file = FileWork();
        QString inputName(argv[1]);
        QString outputName(argv[2]);
        file.setInputFile(inputName);
        file.setOutputFile(outputName);

        QDomNode firstNode = file.getFirstNode(); //Получить внешний узел входного дерева и всё его содержимое.

        makeConjunctiveDisjunctiveForm(firstNode); // Преобразовать выражение к конъюнктивно-дизъюнктивной форме.

        deMorganAndNegationTransformations(firstNode); // Удалить двойные отрицания и раскрыть по законам де Моргана

        file.writeXmlFile(firstNode); // Записать изменённое дерево в выходной XMLфайл.
    }
    catch (int errorCode)
    {
        errorHandler(errorCode); // Обработать полученный код ошибки и вывести сообщение.
        return errorCode;
    }
    return 0;
}
