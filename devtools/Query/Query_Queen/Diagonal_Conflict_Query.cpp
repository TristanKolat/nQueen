// Diagonal_Conflict_Query.cpp

#include "Diagonal_Conflict_Query.h"

Diagonal_Conflict_Query::Diagonal_Conflict_Query(Array<int> &board, int col, int row)
    : board_(board),
      col_(col),
      row_ (row) 
{}

bool Diagonal_Conflict_Query::execute() {
    // Iterate over the entire board to check for diagonal conflicts
    for (Array_Iterator<int> board_iter(board_); !board_iter.is_done(); board_iter.advance()) {
        size_t currColumn = board_iter.Index();
        int currRow = *board_iter;

        // Skip the current queen's position
        if (currColumn == col_) {
            continue;
        }

        // Calculate the difference in columns between the current column and the target column.
        int columnDiff = currColumn > col_ ? currColumn - col_ : col_ - currColumn;
        // Calculate the difference in rows between the current row and the target row
        int rowDiff = currRow > row_ ? currRow - row_ : row_ - currRow;

        // Check if the differences are the same, which would mean they're on the same diagonal
        if (columnDiff == rowDiff) {
            return true; // Conflict found
        }
    }

    return false; // No conflict found
}
