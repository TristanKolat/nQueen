// PlaceQueenCommand.cpp

#include "Place_Queen_Command.h"
#include <iostream>

Place_Queen_Command::Place_Queen_Command(Array<int> &board, int col, int row)
    : board_(board),
      col_(col),
      row_(row)
{}

void Place_Queen_Command::execute(void) {
    std::cout << "\ncur_size: " << board_.size();
    board_.set(col_, row_);
    std::cout << "\ncol: " << col_;
    std::cout << "\nrow: " << board_.get(col_) << std::endl;

}
