#ifndef TREEFUNCTIONS_H
#define TREEFUNCTIONS_H
#include <QDomNode>
#include <QList>
#include <QDomDocument>


/*!
 * \brief treeComparison copmpares two QDomNode trees.
 * \param firstTree - first tree for comparison.
 * \param secondTree - second tree for comparison.
 * \return sucсess of operation: 1 if success, 0 if failure.
 */
int treeComparison(const QDomNode &firstTree, const QDomNode &secondTree);

/*!
 * \brief treeToList decomposes the tree into a list by DFS.
 * \param tree - tree for decomposing.
 * \param treeList - result list of nodes.
 */
void treeToList(const QDomNode & tree, QList <QDomNode> &treeList);

#endif // TREEFUNCTIONS_H
