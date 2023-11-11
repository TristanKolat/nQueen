// Horizontal_Conflict_Command.h
/**
 * @author Tristan Kolat
 * 
 * @date   Nov 11th, 2023
 * 
 * @brief Command to check for horizontal conflicts on a chessboard for the N-Queens problem.
 */

#ifndef _HORIZONTAL_CONFLICT_COMMAND_H_
#define _HORIZONTAL_CONFLICT_COMMAND_H_

#include "../Interface/Expr_Command.h"
#include "../../Array/Array.h"
#include "../../Iterator/iterArray/Array_Iterator.h"

class Horizontal_Conflict_Command : public Expr_Command {
public:
    /** Construct a reference to the entire Board(Array) and row number
     * @param[in]   Array<int> &board   a reference to the chessboard
     * @param[in]   int row             row number being checked
     * */
    Horizontal_Conflict_Command(Array<int> &board, int row);
    /**
     * execute checking horizontal conflict
     * 
     * @return      true if conflict, false otherwise
    */
    virtual bool execute(void);

private:
    Array<int> &board_;
    int row_;
};

#endif // !_HORIZONTAL_CONFLICT_COMMAND_H_
