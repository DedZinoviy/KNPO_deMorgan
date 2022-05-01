#ifndef TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
#define TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
#include <QtTest>
#include <QDomDocument>

// add necessary includes here

class test_makeDeMorganExpressionOfNegations : public QObject
{
    Q_OBJECT

public:
    test_makeDeMorganExpressionOfNegations();
    ~test_makeDeMorganExpressionOfNegations();

private slots:
    void test_case1();

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

#endif // TEST_MAKEDEMORGANEXPRESSIONOFNEGATIONS_H
