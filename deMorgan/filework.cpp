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
