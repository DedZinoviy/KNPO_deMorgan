#include "treeFunctions.h"

int treeComparison(const QDomNode &firstTree, const QDomNode &secondTree)
{
    return 0;
}

void treeToList(const QDomNode & tree, QList <QDomNode> &treeList)
{
    treeList.append(tree); // Добавить текущий узел в список.
    QDomNodeList childList = tree.childNodes(); // Получить дочерние узлы от текущего.
    if (childList.isEmpty()) return; // Если их не существует, то прекратить запись.
    else //Иначе...
    {
        for(int i = 0; i < childList.size(); i++) // Для каждого дочернего узла...
        {
            treeToList(childList.item(i), treeList); // декомпозировать поддерево в список.
        }
    }
}
