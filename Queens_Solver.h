// Queens_Solver.h

#ifndef QUEENS_SOLVER_H
#define QUEENS_SOLVER_H

#include "devtools/Factory/Main_Factory/Concrete_Factory.h"
#include "devtools/Factory/Cmd_Factory/Concrete_Expr_Command_Factory.h"
#include "devtools/Factory/Query_Factory/Concrete_Expr_Query_Factory.h"
#include "devtools/Stack/Stack.cpp"
#include "devtools/Array/Array.h"

/**
 * @class Queens_Solver
 * @brief Solves the N-Queens problem and stores all possible solutions.
 * 
 * @author Tristan Kolat
 * 
 * This class implements the algorithm to find all valid solutions to the N-Queens problem,
 * where no two queens threaten each other. It uses a stack to store each unique solution as an
 * Array of integers, where each integer represents the queen's row position in the corresponding column.
 */
class Queens_Solver {
    public:
        /**
         * @brief Constructor for Queens_Solver that initializes the solver with a specific board size.
         * @param solutions Reference to a stack for storing the solutions found.
         */
        Queens_Solver(Stack<Array<int>>& solutions, int numQueens, int MAX);

        /**
         * @brief Solves the N-Queens problem.
         * 
         * Uses backtracking to place queens on the board and store all non-conflicting
         * configurations in the solutions stack.
         */
        void solve();


        /**
         * @brief Function to set the maximum number of solutions the solver should find.         * 
         * @param max_size variable for inputting new max size
        */ 
        void set_max_solutions_size(int max_size);

        /**
         * @brief Function returns the current max size
        */ 
        int get_max_solutions_size(void);


    private:
        /**
         * @brief Recursively attempts to place queens on the board.
         * 
         * This method is used internally by the solve method to try placing a queen on every row
         * of the given column and recursively calling itself for the next column until all queens are placed
         * on the board without any conflicts.
         * 
         * @param col The current column to place the queen in.
         * @param board The current state of the board represented by an array.
         */
        bool solve_placements(Array<int>& board, int col);

        /**
         * @brief Checks if a queen is not under attack at a given position.
         * 
         * Determines if a queen can be placed at the specified row and column without being
         * attacked based on the current state of the board. It checks for horizontal and diagonal
         * conflicts with any existing queens.
         * 
         * @param row The row position to check.
         * @param col The column position to check.
         * @param board The current state of the board.
         * @return true if the queen is not under attack, false otherwise.
         */
        bool is_Safe(Array<int>& board, int col, int row);

        /**
         * @brief Places a queen on the chessboard at the specified location.
         *
         * This method initializes the command factory to create a place queen command object,
         * which encapsulates the action of placing a queen on the board. The command is then
         * executed to place the queen at the given row and column on the board.
         *
         * @param board A reference to the board array where the queen is to be placed.
         * @param col The column index on the board where the queen is to be placed.
         * @param row The row index on the board where the queen is to be placed.
        */
        void place_queen(Array<int>& board, int col, int row);

        /**
         * @brief Removes a queen from the chessboard at the specified column.
         *
         * This method utilizes the command factory to create a remove queen command object,
         * which encapsulates the action of removing a queen from the board. The command is
         * then executed to remove the queen from the given column, effectively setting the
         * column's value back to -1 to indicate that no queen is placed in that column.
         *
         * @param board A reference to the board array from which the queen is to be removed.
         * @param col The column index on the board where the queen is to be removed.
        */
        void remove_queen(Array<int>& board, int col);

        Stack<Array<int>>& solutions_; // Reference to a stack to store all valid board configurations.
        Concrete_Factory factory; // Factory to create command and query objects.
        Expr_Command_Factory* command_factory;
        Expr_Query_Factory* query_factory;
        int numQueens_;

        //variable to declare a max amount of solutions to find
        int max_solutions_;
};

#endif // QUEENS_SOLVER_H