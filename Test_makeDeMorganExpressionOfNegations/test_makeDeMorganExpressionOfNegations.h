#ifndef TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
#define TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
#include <QtTest>
#include <QDomDocument>
#include "../deMorgan/main.h"

// add necessary includes here

class test_makeDeMorganExpressionOfNegations : public QObject
{
    Q_OBJECT

public:
    test_makeDeMorganExpressionOfNegations();
    ~test_makeDeMorganExpressionOfNegations();

private slots:
    void makeDisjunctionOfNegations();
    void makeConjunctionOfNegations();
    void makeDisjunctionOfNegationsWithComplexExpressions();
    void makeConjunctionOfNegationsWithComplexExpressions();
};


/*!
* \brief treeComparison copmpares two QDomNode trees.
* \param firstTree - first tree for comparison.
* \param secondTree - second tree for comparison.
* \return sucсess of operation: true if success, false if failure.
*/
bool treeComparison(const QDomNode &firstTree, const QDomNode &secondTree);

/*!
* \brief treeToList decomposes the tree into a list by DFS.
* \param tree - tree for decomposing.
* \param treeList - result list of nodes.
*/
void treeToList(const QDomNode & tree, QList <QDomNode> &treeList);

/*!
 * \brief getFirstNode returns the first root node of the tree from the specified xml file.
 * \param inputFileName path to the file.
 * \return first node of tree.
 */
QDomNode getFirstNode(QString inputFileName);

#endif // TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
