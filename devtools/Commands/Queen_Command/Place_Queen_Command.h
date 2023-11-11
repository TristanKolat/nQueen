// PlaceQueenCommand.h
/**
 * @author Tristan Kolat
 * 
 * @date   Nov 11th, 2023
 * 
 * @class A command to place a queen on the chessboard for the N-Queens problem.
 * @return a boolean showing if command was successful or not
*/

#ifndef _PLACE_QUEEN_COMMAND_H_
#define _PLACE_QUEEN_COMMAND_H_

#include "../Interface/Expr_Command.h"
#include "../../Array/Array.h"
#include "../../Iterator/iterArray/Array_Iterator.h"


class Place_Queen_Command : public Expr_Command {
public:
    // Construct a reference to the Board(Array) and row number
    Place_Queen_Command(Array_Iterator<int> &iter, int row);
    virtual ~Place_Queen_Command() { }
    //execute placing the queen onto the board array
    virtual bool execute(void);

private:
    //referenced column from the iterator in the chess board array for assigning a row number 
    Array_Iterator<int> &iter_;
    //row number to place queen
    int row_;
};

#endif // !_PLACE_QUEEN_COMMAND_H_
