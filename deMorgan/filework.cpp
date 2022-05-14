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
