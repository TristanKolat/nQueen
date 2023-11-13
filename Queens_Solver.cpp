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

}

bool Queens_Solver::is_Safe(Array<int>& board, int col ,int row) {

}

Stack<Array<int>>& Queens_Solver::get_solutions() const {

}

