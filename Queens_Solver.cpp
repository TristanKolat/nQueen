// Queens_Solver.cpp

#include "Queens_Solver.h"

Queens_Solver::Queens_Solver(Stack<Array<int>>& solutions, int numQueens)
: solutions_(solutions),
  numQueens_(numQueens),
  factory() 
{}

void Queens_Solver::solve() {
    // Initialize the board with -1 representing no queen placed
    Array<int> board(numQueens_, -1);
    // Start the recursive proccess that solves all solutions for placed queens
    solve_placements(board, 0);
}

void Queens_Solver::solve_placements(Array<int>& board, int col) {
    //check if all queens have been placed
    //if column equals the size of board then all queens have been placed
    if (col == board.size()) {
        solutions_.push(board);
        return;
    }

    for (int row = 0; row < board.size(); row++) {
        //if queen is safe in current row then place the queen
        if (is_Safe(board, col, row)) {
            auto command_factory = factory.create_command_factory();
            auto place_queen_command = command_factory -> create_place_queen_command(board, col, row);
            place_queen_command -> execute();

            //once queen is placed then recursively recall the function to start the next rows evaluation
            solve_placements(board, col++);

            //remove the queens after recursion for finding every possible solution
            auto remove_queen_command = command_factory -> create_remove_queen_command(board, col);
            remove_queen_command -> execute();
        }
    }
}

bool Queens_Solver::is_Safe(Array<int>& board, int col ,int row) {
    //make horizontal and diagonal conflict query's
    auto query_factory = factory.create_query_factory();
    auto horizontal_conflict_query = query_factory -> create_horizontal_conflict_query(board, row);
    auto diagonal_conflict_query = query_factory -> create_diagonal_conflict_query(board, col, row);

}

Stack<Array<int>>& Queens_Solver::get_solutions() const {

}

