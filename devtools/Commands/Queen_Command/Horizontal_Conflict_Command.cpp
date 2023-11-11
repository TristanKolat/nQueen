#include "Horizontal_Conflict_Command.h"

Horizontal_Conflict_Command::Horizontal_Conflict_Command(Array<int> &board, int row)
    : board_(board),
      row_(row) 
{}

bool Horizontal_Conflict_Command::execute(void) {
    // Create an iterator to iterate from the beginning of the array (board)
    // Iterate over the entire array to check for a queen in the same row
    for (Array_Iterator<int> board_iter(board_); !board_iter.is_done(); board_iter.advance()) {
        //check if the iterated row conflicts with the row being checked
        if (*board_iter == this->row_) {
            return true; // Conflict found
        }
    }

    return false; // No conflict found
}

