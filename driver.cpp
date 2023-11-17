#include "Queens_Solver.h"
#include "devtools/Array/Array.h"
#include "devtools/Stack/Stack.h"
#include "devtools/Iterator/iterArray/Array_Iterator.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    // Initialize the solutions stack
    Stack<Array<int>> solutions;
    // Variable to hold user input for the number of queens
    std::string input;
    // Define the maximum number of solutions allowed
    int MAX = 14500;

    // Start the loop for user interaction
    while (true) {
        // Ask user for the number of queens and store input
        std::cout << "------------------\nHow many Queens?\n------------------\n-Type QUIT to exit-\n\n";
        std::cin >> input;

        // If user inputs QUIT, then break the loop
        if (input == "QUIT") {
            break;
        }

        // Clear previous solutions from the stack
        solutions.clear();

        // Pass user integer value and solutions stack into queens solver
        // Start recursion with solve()
        Queens_Solver algorithm(solutions, std::stoi(input), MAX);
        algorithm.solve();

        // Display to the user how many solutions were found
        std::cout << solutions.size() << " solutions found for this size\n";
        if (solutions.size() >= MAX) {
            std::cout << "------------------\n    WARNING\n------------------\n";
            std::cout << "Max solution size has been reached (>= " << MAX << " solutions found)\n";
            std::cout << "This may not correctly demonstrate the amount of solutions.\n";
            std::cout << "(Change MAX variable in driver to change size)\n";
            std::cout << "--------------------------------------\n\n";
        }

        // Make a do-while loop to show solutions to the user
        std::string nextInput;
        do {
            // Check that the stack is not empty
            if (solutions.is_empty()) {
                std::cout << "No more solutions to display.\n";
                break;
            }

            // Show the board at the top of the stack
            Array<int> solution = solutions.top();
            std::cout << solution.size();

            // Iterate over each row (which is represented by each item in the solution array)
            for (Array_Iterator<int> iter(solution); !iter.is_done(); iter.advance()) {
                // Get the column index where the queen is placed for this row
                int queenColumn = *iter;

                // Print the board for the current row
                for (int col = 0; col < solution.size(); col++) {
                    if (col == queenColumn) {
                        std::cout << 'Q' << " "; // Queen is placed in this column
                    } else {
                        std::cout << '-' << " "; // Empty square
                    }
                }
                std::cout << std::endl; // Newline at the end of the row
            }
            std::cout << std::endl;

            // Ask user if they would like to see the next solution or choose another size
            std::cout << "Would you like to see the next solution? (YES to continue, NO to choose another size): ";
            std::cin >> nextInput;

            // If yes, pop stack then let loop rerun to show next board
            if (nextInput == "YES" || nextInput == "yes") {
                solutions.pop();
            }

        // Break the do-while loop if the user wants to go back
        } while (nextInput == "YES" || nextInput == "yes");

        // End do-while loop
    }

    return 0;
}
