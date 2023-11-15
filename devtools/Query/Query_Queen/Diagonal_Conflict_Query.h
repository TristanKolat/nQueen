// Diagonal_Conflict_Query.h
/**
 * @author Tristan Kolat
 * 
 * @date   Nov 11th, 2023
 * 
 * @brief Query to check for diagonal conflicts on a chessboard for the N-Queens problem.
 */

#ifndef _DIAGONAL_CONFLICT_QUERY_H_
#define _DIAGONAL_CONFLICT_QUERY_H_

#include "../Interface/Expr_Query.h"
#include "../../Iterator/iterArray/Array_Iterator.h"

/**
 * @class Diagonal_Conflict_Query
 * @brief Query class to check for diagonal conflicts on the chessboard.
 *
 * Inherits from Expr_Query and overrides the execute method to determine
 * if there is any queen that conflicts diagonally with the queen at the iterator's position.
 */
class Diagonal_Conflict_Query : public Expr_Query {
public:
    /** Construct a reference to the entire Board(Array) and current iteration (gives row and col)
     * @param[in]   Array<int> &board               a reference to the chessboard
     * @param[in]   int row, col       col & row numbers being checked
     * */
    Diagonal_Conflict_Query(Array<int> &board, int col, int row);
    /**
     * execute checking horizontal conflict query
     * 
     * @return      true if conflict, false otherwise
    */
    virtual bool execute();

private:
    Array<int> &board_;
    int col_;
    int row_;
};

#endif // !_DIAGONAL_CONFLICT_QUERY_H_
