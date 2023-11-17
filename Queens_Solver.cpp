// Queens_Solver.cpp

#include "Queens_Solver.h"

// Constructor that sets up the command and query factories needed for solving the N-Queens problem.
Queens_Solver::Queens_Solver(Stack<Array<int>>& solutions, int numQueens, int MAX)
: solutions_(solutions),
  numQueens_(numQueens),
  max_solutions_(MAX),
  factory(),
  command_factory(factory.create_command_factory()),
  query_factory(factory.create_query_factory())
{}

// Initiates the recursive process to find all possible queen placements on the board.
void Queens_Solver::solve() {
    // Initialize the board with -1 representing no queen placed
    Array<int> board(numQueens_, -1);
    // Start the recursive proccess that solves all solutions for placed queens
    solve_placements(board, 0);
}

// Internal recursive function that attempts to place a queen in the current column
// and proceeds to the next column if successful.
bool Queens_Solver::solve_placements(Array<int>& board, int col) {
    //check if all queens have been placed
    //if column equals the size of board then all queens have been placed
    if (col == board.size()) {
        solutions_.push(board);
        return max_solutions_ > 0 && solutions_.size() >= max_solutions_;
            
    }
        for (int row = 0; row < board.size(); row++) {
            //if queen is safe in current row then place the queen
            if (is_Safe(board, col, row)) {
                //places the queen on the board in the (col, row)
                place_queen(board, col, row);

                //once queen is placed then recursively recall the function to start the next rows evaluation
                //uses col + 1 so that the original value of col remains unchanged
                //  so that after a recursive call returns, the for-loop continues trying to place a queen in the next row of the same column
                if (solve_placements(board, col + 1)) {
                    return true;
                }

                //remove the queens after recursion for finding every possible solution
                remove_queen(board, col);
            }
        }
    return false;
}

bool Queens_Solver::is_Safe(Array<int>& board, int col ,int row) {
    //make horizontal and diagonal conflict query's
    auto horizontal_conflict_query = query_factory -> create_horizontal_conflict_query(board, row);
    auto diagonal_conflict_query = query_factory -> create_diagonal_conflict_query(board, col, row);

    //return AND logic boolean checking for conflicts horizontally and diagonally
    return !horizontal_conflict_query->execute() && !diagonal_conflict_query->execute();
}

void Queens_Solver::place_queen(Array<int>& board, int col, int row) {
    auto place_queen_command = command_factory->create_place_queen_command(board, col, row);
    place_queen_command->execute();
}

void Queens_Solver::remove_queen(Array<int>& board, int col) {
    auto remove_queen_command = command_factory -> create_remove_queen_command(board, col);
    remove_queen_command -> execute();
}

void Queens_Solver::set_max_solutions_size(int max_size) {
    // Set the maximum number of solutions for the nQueens problem
    this->max_solutions_ = max_size;
}


int Queens_Solver::get_max_solutions_size(void) {
    // Get the current maximum number of solutions limit.
    return this->max_solutions_;
}

