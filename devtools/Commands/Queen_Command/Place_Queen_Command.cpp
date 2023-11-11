// PlaceQueenCommand.cpp

#include "Place_Queen_Command.h"

Place_Queen_Command::Place_Queen_Command(Array_Iterator<int> &iter, int row)
    : iter_(iter), 
      row_(row) 
{}

void Place_Queen_Command::execute(void) {
    // The iterator should already be at the correct column.
    if (!iter_.is_done()) {
        *iter_ = row_; // Place the queen at the current iterator position, which is the correct column.
    }// assuming command is always succesful
}
