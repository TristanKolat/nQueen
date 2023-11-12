/**
 * @file Concrete_Expr_Command_Factory.cpp
 * @author Tristan Kolat
 * 
 * @date Nov 11th, 2023
 * 
 * @brief Implementation of the Concrete_Expr_Command_Factory class
 */

#include "Concrete_Expr_Command_Factory.h"

/**
 * Creates and returns a new Place_Queen_Command.
 * This command will place a queen at the specified row on the board.
 *
 * @param[in]   board   Reference to the chessboard represented by Array<int>.
 * @param[in]   row     The row on the board where the queen is to be placed.
 * @return      A pointer to the newly created Place_Queen_Command object.
 */
Place_Queen_Command* Concrete_Expr_Command_Factory::create_place_queen_command(Array<int> &board, int row) {
    Array_Iterator<int> iter(board);
    return new Place_Queen_Command(iter, row);
}

/**
 * Creates and returns a new Remove_Queen_Command.
 * This command will remove a queen from the specified row on the board.
 *
 * @param[in]   board   Reference to the chessboard represented by Array<int>.
 * @param[in]   row     The row on the board from which the queen is to be removed.
 * @return      A pointer to the newly created Remove_Queen_Command object.
 */
Remove_Queen_Command* Concrete_Expr_Command_Factory::create_remove_queen_command(Array<int> &board, int row) {
    Array_Iterator<int> iter(board);
    return new Remove_Queen_Command(iter);
}
