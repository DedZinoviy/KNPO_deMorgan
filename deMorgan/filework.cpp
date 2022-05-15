#include "filework.h"

FileWork::FileWork()
{

}

bool FileWork::isXMLFile(QString &name)
{
    if (!name.endsWith(".xml", Qt::CaseSensitive)) // Сообщить,если указанный файл не является .xml
        throw 3;
    return true;
}

bool FileWork::isCorrectOutput(QString & name)
{
    QFileInfo outputFile(name);
    if (isXMLFile(name)) // Если указанный файл все же является .xml
    {
        if (!outputFile.dir().exists()) throw 2; // Сообщить,если указанного файла не существует
    }
    return true;
}

bool FileWork::isCorrectInput(QString & name)
{
    QFile inputFile(name);
    QDomDocument doc(name);
    QString error;
    if(isXMLFile(name)) // Если указанный файл все же является .xml
    {
        if (!inputFile.open(QIODevice::ReadOnly)) throw 1;//Сообщить, если указанного файла не существует
        else if (!doc.setContent(&inputFile, true, &error)) //Сообщить, если файл содержит синтаксическую ошибку
        {
            std::cout << error.data() <<std::endl;
            throw 15;
        }
    }
    return true;
}

bool FileWork::setInputFile(QString fileName)
{
    if (isCorrectInput(fileName))
    {
        this->inputFileName = fileName;
        return true;
    }
    else return false;
}

bool FileWork::setOutputFile(QString fileName)
{
    if (isCorrectOutput(fileName))
    {
        this->outputFileName = fileName;
        return true;
    }
    else return false;
}

QDomNode FileWork::getFirstNode()
{
    // Получить имя xml файла, в котором требуется найти первый узел
    QDomDocument document(this->inputFileName);
    QFile inputFile(this->inputFileName);

    // Открыть указанный файл для работы с ним
    inputFile.open(QIODevice::ReadOnly);
    document.setContent(&inputFile);
    inputFile.close();

    // Получить первый узел дерева разбора.
    QDomElement docObject = document.documentElement();
    return docObject;
}

bool FileWork::writeXmlFile(QDomNode &tree)
{
    // Получить имя xml файла, в который требуется записать дерево
    QDomDocument document(this->outputFileName);
    document.appendChild(tree);
    QFile file(this->outputFileName);

    // Записать дерево в файл, если удалось его открыть
    if (file.open(QIODevice::WriteOnly))
    {
         QTextStream stream(&file);
         stream << document.toString();
         file.close();
         return true;
    }
    return false;
}
