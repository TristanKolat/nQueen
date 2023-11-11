// Remove_Queen_Command.h
/**
 * @author Tristan Kolat
 * 
 * @date   Nov 11th, 2023
 * @class A command to remove a queen from the chessboard for the N-Queens problem.
 * @return a boolean showing if command was successful or not
 */

#ifndef _REMOVE_QUEEN_COMMAND_H_
#define _REMOVE_QUEEN_COMMAND_H_

#include "../Interface/Expr_Command.h"
#include "../../Iterator/iterArray/Array_Iterator.h"

class Remove_Queen_Command : public Expr_Command {
public:
    // Construct a reference to the Board(Array) iterator
    Remove_Queen_Command(Array_Iterator<int> &iter);
    virtual ~Remove_Queen_Command() { }
    // Execute removal of the queen from the board array
    virtual void execute(void);

private:
    // Referenced iterator in the chess board array to remove a queen from
    Array_Iterator<int> &iter_;
};

#endif // !_REMOVE_QUEEN_COMMAND_H_
