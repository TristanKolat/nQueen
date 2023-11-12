// Remove_Queen_Command.h
/**
 * @author Tristan Kolat
 * 
 * @date   Nov 11th, 2023
 * @class A command to remove a queen from the chessboard for the N-Queens problem.
 * @return a boolean showing if command was successful or not
 */


#include "Remove_Queen_Command.h"

Remove_Queen_Command::Remove_Queen_Command(Array<int> &board, int col)
    : board_(board),
      col_(col)
{}

void Remove_Queen_Command::execute(void) {
    board_.set(col_, -1);
}
