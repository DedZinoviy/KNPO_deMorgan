/*!
 * \file
 * \brief Header file with description of structures and function prototypes.
 *
 * This file contains a description of all the structures,
 * enumerations and functions used in the program.
*/

#ifndef MAIN_H
#define MAIN_H
#include <QCoreApplication>
#include <QDomDocument>
#include <QMap>
#include "filework.h"

//! Enumeration for the description of de Morgan's laws.
enum DeMorganLaws
{
    FIRST,  ///< First de Morgan Law defenition
    SECOND  ///< Second de Morgan Law defenition
};

#endif // MAIN_H

/*!
 * \brief makeDeMorganExpressionOfNegations makes block of nodes (disjunction or conjunction of negations) according to de Morgan laws.
 * \param[in] firstChild - first child node for the expression being created.
 * \param[in] secondChild - second child node for the expression being created.
 * \param[in] type - type of de Morgan Law - first or second.
 * \return expression of negations in QDomNode form.
 */
QDomNode makeDeMorganExpressionOfNegations(QDomNode &firstChild, QDomNode &secondChild, DeMorganLaws type);

/*!
 * \brief makeConjunctiveDisjunctiveForm rebuilds the parsing tree into conjunctive-disjunctive form, convert all operations to conjunctions, disjunctions and negations.
 * \param[in,out] node - the node of the tree from which the transformation will begin.
 */
void makeConjunctiveDisjunctiveForm(QDomNode & node);

/*!
 * \brief deMorganAndNegationTransformations deletes double negtions and uses de Morgan Laws for deleting negations of conjunction or disjunction.
 * \param[in,out] node - the node of tree from which the transformation will begin.
 */
void deMorganAndNegationTransformations(QDomNode& node);

/*!
 * \brief errorHandler puts tha error massege string into console output.
 * \param[in] errorCode - integer code of error from functions.
 * \return error error code to the console.
 */
int errorHandler(int errorCode);

/*!
 * \brief isCorrectNode checks the node for the presence of erroneous situations in it, such as a mismatch in the number of child nodes.
 * \param[in] node - a logical operation node that is checked for errors.
 * \throw 4 - There is no parse tree in the specified file, or the parse tree is unreadable in it.
 * \throw 5 - The specified file contains tags that do not belong to valid.
 * \throw 6 - Root node contains more than one child node.
 * \throw 7 - The negation operation has no child operand node.
 * \throw 8 - File contains more than one parse tree.
 * \throw 9 - Binary operations have more than two operands.
 * \throw 10 - Binary operations have a lack of operands.
 * \throw 11 - The negation operation has more than one child node.
 * \throw 12 - The variable has an invalid child tag.
 * \throw 13 - Operation tag is missing a type attribute.
 * \throw 14 - The operation tag is of an invalid type.
 * \throw 17 - The text node is not a child node of the variable.
 */
void isCorrectNode(const QDomNode &node);
