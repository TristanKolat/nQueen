// Queens_Solver.h

#ifndef QUEENS_SOLVER_H
#define QUEENS_SOLVER_H

#include "devtools/Factory/Main_Factory/Concrete_Factory.h"
#include "devtools/Factory/Cmd_Factory/Concrete_Expr_Command_Factory.h"
#include "devtools/Factory/Query_Factory/Concrete_Expr_Query_Factory.h"
#include "devtools/Stack/Stack.h"
#include "devtools/Array/Array.h"

/**
 * @class Queens_Solver
 * @brief Solves the N-Queens problem and stores all possible solutions.
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
        Queens_Solver(Stack<Array<int>>& solutions);

        /**
         * @brief Solves the N-Queens problem.
         * 
         * Uses backtracking to place queens on the board and store all non-conflicting
         * configurations in the solutions stack.
         */
        void solve();

        /**
         * @brief Getter for the stack of solutions.
         * @return Reference to the stack of solutions.
         */
        Stack<Array<int>>& get_solutions() const;
        
    private:
        Stack<Array<int>>& solutions; ///< Reference to a stack to store all valid board configurations.
        Concrete_Factory factory; ///< Factory to create command and query objects.
};

#endif // QUEENS_SOLVER_H

