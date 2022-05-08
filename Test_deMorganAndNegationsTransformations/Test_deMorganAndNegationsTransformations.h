#ifndef TEST_DEMORGANANDNEGATIONSTRANSFORMATIONS_H
#define TEST_DEMORGANANDNEGATIONSTRANSFORMATIONS_H
#include "../deMorgan/main.h"
#include <QtTest>

// add necessary includes here

class test_deMorganAndNegationsTransformations : public QObject
{
    Q_OBJECT

public:
    test_deMorganAndNegationsTransformations();
    ~test_deMorganAndNegationsTransformations();
private:
    /*!
     * \brief getFirstNode returns the first root node of the tree from the specified xml file.
     * \param inputFileName path to the file.
     * \return first node of tree.
     */
    QDomNode getFirstNode(QString inputFileName);

    /*!
    * \brief treeToList decomposes the tree into a list by DFS.
    * \param tree - tree for decomposing.
    * \param treeList - result list of nodes.
    */
    void treeToList(const QDomNode & tree, QList <QDomNode> &treeList);

    /*!
    * \brief treeComparison copmpares two QDomNode trees.
    * \param firstTree - first tree for comparison.
    * \param secondTree - second tree for comparison.
    */
    void treeComparison(const QDomNode &firstTree, const QDomNode &secondTree);

private slots:
    void emptyTree();
    void onlyExpressionTag();
    void onlyOneNegation();
    void doubleNegation();
    void negationOfDoubleNegation();
    void twoDoubleNegationsAtRow();
    void twoNegationsInDifferentBranches();
    void noSuitableSituations();
    void oneFirstDeMorganSituation();
    void oneSecondDeMorganSituation();
    void twoFirstDeMorganSituationsInRow();
    void twoFirstDemorganSituationsInDifferentBranches();
    void twoSecondDeMorganSituationsInRow();
    void twoSecondDeMorganSituationsInDifferentBranches();
    void combinationOfDoubleNegationAndFirstDeMorganInRow();
    void combinationOfDoubleNegationAndSecondDeMorganInRow();
    void combinationOfDoubleNegationAndFirstDeMorganInDifferentBranches();
    void combinationOfDoubleNegationAndSecondDeMorganInDifferentBranches();
    void combinationOfSecondDeMorganAndFirstDeMorganInRow();
    void combinationOfSecondDeMorganAndSecondDeMorganInDifferentBranches();
    void negationOfFirstDeMorgan();
    void negationOfSecondDeMorgan();
    void complexTest();

};
#endif // TEST_DEMORGANANDNEGATIONSTRANSFORMATIONS_H
