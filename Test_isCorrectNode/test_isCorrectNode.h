#ifndef TEST_ISCORRECTNODE_H
#define TEST_ISCORRECTNODE_H
#include <QDomDocument>
#include <QtTest>
#include "../deMorgan/main.h"
// add necessary includes here

class Test_isCorrectNode : public QObject
{
    Q_OBJECT

public:
    Test_isCorrectNode();
    ~Test_isCorrectNode();
private:
    /*!
     * \brief getFirstNode returns the first root node of the tree from the specified xml file.
     * \param inputFileName path to the file.
     * \return first node of tree.
     */
    QDomNode getFirstNode(QString inputFileName);

private slots:
    void twoExpressionTagsInRow();
    void twoChildNodesOfExpression();
    void emptyExpression();
    void notRootExpression();
    void nonDeclaredTags();
    void nonDeclaredMixedDeclared();
    void undeclaredOperationAttribute();
    void undeclaredOperationType();
    void lackOfDisjunction();
    void lackOfNand();
    void overageOfConjunction();
    void overageOfNor();
    void overageOfNegation();
    void lackOfNegation();
    void notTextInVariable();
};

#endif // TEST_ISCORRECTNODE_H
