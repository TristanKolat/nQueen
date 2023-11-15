/**
 * @file Concrete_Expr_Query_Factory.cpp
 * @author Tristan Kolat
 * 
 * @date Nov 11th, 2023
 * 
 * @brief Implements the methods of the Concrete_Expr_Query_Factory for creating query objects.
 */

#include "Concrete_Expr_Query_Factory.h"

Horizontal_Conflict_Query* Concrete_Expr_Query_Factory::create_horizontal_conflict_query(Array<int> &board, int row) {
    return new Horizontal_Conflict_Query(board, row);
}

Diagonal_Conflict_Query* Concrete_Expr_Query_Factory::create_diagonal_conflict_query(Array<int> &board, size_t column, int row) {
    return new Diagonal_Conflict_Query(board, column, row);
}
