#ifndef MAIN_H
#define MAIN_H
#include <QCoreApplication>
#include <QDomDocument>
#include "filework.h"

enum DeMorganLaws
{
    FIRST,  // First de Morgan Law defenition
    SECOND  // Second de Morgan Law defenition
};

#endif // MAIN_H

/*!
 * \brief makeDeMorganExpressionOfNegations makes block of nodes (disjunction or conjunction of negations) according to de Morgan laws.
 * \param firstChild - first child node for the expression being created.
 * \param secondChild - second child node for the expression being created.
 * \param type - type of de Morgan Law - first or second.
 * \return expression of negations in QDomNode form.
 */
QDomNode makeDeMorganExpressionOfNegations(QDomNode &firstChild, QDomNode &secondChild, DeMorganLaws type);

/*!
 * \brief makeConjunctiveDisjunctiveForm rebuilds the parsing tree into conjunctive-disjunctive form, convert all operations to conjunctions, disjunctions and negations.
 * \param node - the node of the tree from which the transformation will begin.
 */
void makeConjunctiveDisjunctiveForm(QDomNode & node);

/*!
 * \brief deMorganAndNegationTransformations deletes double negtions and uses de Morgan Laws for deleting negations of conjunction or disjunction.
 * \param node - the node of tree from which the transformation will begin.
 */
void deMorganAndNegationTransformations(QDomNode& node);

/*!
 * \brief errorHandler puts tha error massege string into console output.
 * \param errorCode - integer code of error from functions.
 * \return error error code to the console.
 */
int errorHandler(int errorCode);

/*!
 * \brief isCorrectNode checks the node for the presence of erroneous situations in it, such as a mismatch in the number of child nodes.
 * \param node - a logical operation node that is checked for errors.
 */
void isCorrectNode(const QDomNode &node);
