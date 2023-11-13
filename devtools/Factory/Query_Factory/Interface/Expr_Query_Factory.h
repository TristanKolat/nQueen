/**
 * @file Expr_Query_Factory.h
 * @author Tristan Kolat
 * 
 * @date Nov 11th, 2023
 * 
 * @brief Factory interface for creating query objects related to the N-Queens problem.
 */

#ifndef _EXPR_QUERY_FACTORY_H_
#define _EXPR_QUERY_FACTORY_H_

#include "../../../Query/Query_Queen/Horizontal_Conflict_Query.h"
#include "../../../Query/Query_Queen/Diagonal_Conflict_Query.h"
#include "../../../Array/Array.h"

/**
 * @class Expr_Query_Factory
 * @brief Interface factory for creating query objects.
 *
 * This factory defines the methods for creating query objects that check for conflicts
 * in the N-Queens problem.
 */
class Expr_Query_Factory {
public:
    //virtual ~Expr_Query_Factory() {}

    /**
     * Creates a Horizontal_Conflict_Query object.
     * @param[in]   board   Reference to the chessboard.
     * @param[in]   row     Row to check for horizontal conflicts.
     * @return      Pointer to the created Horizontal_Conflict_Query object.
     */
    virtual Horizontal_Conflict_Query* create_horizontal_conflict_query(Array<int> &board, int row) = 0;

    /**
     * Creates a Diagonal_Conflict_Query object.
     * @param[in]   board   Reference to the chessboard.
     * @param[in]   column  Column to check for diagonal conflicts.
     * @param[in]   row     Row to check for diagonal conflicts.
     * @return      Pointer to the created Diagonal_Conflict_Query object.
     */
    virtual Diagonal_Conflict_Query* create_diagonal_conflict_query(Array<int> &board, size_t column, int row) = 0;
};

#endif // _EXPR_QUERY_FACTORY_H_
