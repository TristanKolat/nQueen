// Diagonal_Conflict_Query.cpp

#include "Diagonal_Conflict_Query.h"

Diagonal_Conflict_Query::Diagonal_Conflict_Query(Array<int> &board, Array_Iterator<int> &iter)
    : board_(board),
      iter_(iter) {
}

bool Diagonal_Conflict_Query::execute() {
    int targetRow = *iter_;
    size_t targetColumn = iter_.Index();

    // Iterate over the entire board to check for diagonal conflicts
    for (Array_Iterator<int> board_iter(board_); !board_iter.is_done(); board_iter.advance()) {
        size_t currColumn = board_iter.Index();
        int currRow = *board_iter;

        // Skip the current queen's position
        if (currColumn == targetColumn) {
            continue;
        }

        // Calculate the difference in columns between the current column and the target column.
        int columnDiff = currColumn > targetColumn ? currColumn - targetColumn : targetColumn - currColumn;
        // Calculate the difference in rows between the current row and the target row
        int rowDiff = currRow > targetRow ? currRow - targetRow : targetRow - currRow;

        // Check if the differences are the same, which would mean they're on the same diagonal
        if (columnDiff == rowDiff) {
            return true; // Conflict found
        }
    }

    return false; // No conflict found
}
