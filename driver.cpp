#include "Queens_Solver.h"
#include "devtools/Array/Array.h"
#include "devtools/Stack/Stack.h"
#include "devtools/Iterator/iterArray/Array_Iterator.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    //initalize solution stack
    Stack<Array<int>> solutions;
    //initialize int for holding users inputted number of queense
    int nQueens;
    //variable for converting user input from string -> int
    std::string input;

    //start loop for user interaction
    while (true) {
        //ask user for number of queens and store input
        std::cout << "How many Queens?\n------------------\n\n--Type QUIT to exit--";
        std::cin >> input;

        //if user inputs QUIT then break loop
        if (input == "QUIT") {
            break;
        }

        //pass user integer value and solutions stack into queens solver
        //start recursion with solve()

        //display to user how many solutions were found

        //make do while loop
        //in do while as user what solution they want to see. 
        //keep looping so that user can view different solutions

        //add another check in case user wants to quit

        //add another check to see if user wants to see all solutions in one display

        //else retrieve the specific solution 
            //store into temp array
            //display that solution held in the temp array

        //end do while loop

        //clear solutions stack in case user wants to try another solution

    }

    return 0;
}