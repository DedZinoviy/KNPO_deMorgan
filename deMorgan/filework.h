#ifndef FILEWORK_H
#define FILEWORK_H
#include <QDomDocument>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

/*!
 * \brief The FileWork class designed to work with input and output xml files.
 */
class FileWork
{
public:
    FileWork();

    /*!
     * \brief setInputFile sets the name of the file to be entered in the FileWork class object.
     * \param fileName - string path to the file.
     * \return success of the operation.
     */
    bool setInputFile(QString fileName);

    /*!
     * \brief setOutputFile sets the name of the output file in the FileWork class object.
     * \param fileName - string path to the file.
     * \return success of the operation.
     */
    bool setOutputFile(QString fileName);

    /*!
     * \brief writeXmlFile writes the tree to an xml file.
     * \param tree - tree to be written.
     * \return sucess of operation.
     */
    bool writeXmlFile(QDomNode &tree);

    /*!
     * \brief getFirstNode allows to get the first node from the parse tree in the XML file.
     * \return fisrt node from parse tree.
     */
    QDomNode getFirstNode();

    /*!
     * \brief isXMLFile сhecks whether the specified file is an XML file.
     * \param name - file name with its path.
     * \return success of operation.
     */
    bool isXMLFile(QString &name);

    /*!
     * \brief isCorrectOutput checks the output file name for correctness.
     * \param name - file name with its path.
     * \return success of operation.
     */
    bool isCorrectOutput(QString & name);
private:
    QString inputFileName; ///< string path to input file.
    QString outputFileName; ///< string path to output file.
};

#endif // FILEWORK_H
