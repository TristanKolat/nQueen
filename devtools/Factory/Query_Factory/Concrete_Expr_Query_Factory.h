/**
 * @file Concrete_Expr_Query_Factory.h
 * @author Tristan Kolat
 * 
 * @date Nov 11th, 2023
 * 
 * @brief Concrete factory for creating query objects related to the N-Queens problem.
 */

#ifndef _CONCRETE_EXPR_QUERY_FACTORY_H_
#define _CONCRETE_EXPR_QUERY_FACTORY_H_

#include "Interface/Expr_Query_Factory.h"

/**
 * @class Concrete_Expr_Query_Factory
 * @brief Concrete factory for creating query objects.
 *
 * Implements Expr_Query_Factory to provide concrete query objects for checking
 * conflicts in the N-Queens problem.
 */
class Concrete_Expr_Query_Factory : public Expr_Query_Factory {
public:
    Horizontal_Conflict_Query* create_horizontal_conflict_query(Array<int> &board, int row);
    Diagonal_Conflict_Query* create_diagonal_conflict_query(Array<int> &board, size_t column, int row);
};

#endif // _CONCRETE_EXPR_QUERY_FACTORY_H_
