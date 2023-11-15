// PlaceQueenCommand.cpp

#include "Place_Queen_Command.h"

Place_Queen_Command::Place_Queen_Command(Array<int> &board, int col, int row)
    : board_(board),
      col_(col),
      row_(row)
{}

void Place_Queen_Command::execute(void) {
    board_.set(col_, row_);
}
