// Remove_Queen_Command.h
/**
 * @author Tristan Kolat
 * 
 * @date   Nov 11th, 2023
 * @class A command to remove a queen from the chessboard for the N-Queens problem.
 * @return a boolean showing if command was successful or not
 */


#include "Remove_Queen_Command.h"

Remove_Queen_Command::Remove_Queen_Command(Array_Iterator<int> &iter)
    : iter_(iter) 
{}

bool Remove_Queen_Command::execute(void) {
    // The iterator should already be at the correct column.
    if (!iter_.is_done()) {
        *iter_ = -1; // Remove the queen by setting the column to -1, indicating no queen is placed.
    }
    return true; // asuming command is always successful
}
