/**
 * @file Expr_Command_Factory.h
 * @author Tristan Kolat
 * 
 * @date Nov 11th, 2023
 * 
 * @brief factory interface for creating command objects related to placing and removing queens in the N-Queens problem.
 */

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "../../../Commands/Queen_Command/Place_Queen_Command.h"
#include "../../../Commands/Queen_Command/Remove_Queen_Command.h"
#include "../../../Array/Array.h"

/**
 * @class Expr_Command_Factory
 * @brief interface factory for creating command objects.
 *
 */
class Expr_Command_Factory {
public:
    /**
     * Creates a Place_Queen_Command object.
     * @param[in]   board   Reference to the chessboard.
     * @param[in]   row     Row where the queen is to be placed.
     * @return      Pointer to the created Place_Queen_Command object.
     */
    virtual Place_Queen_Command* create_place_queen_command(Array<int> &board, int col, int row) = 0;

    /**
     * Creates a Remove_Queen_Command object.
     * @param[in]   board   Reference to the chessboard.
     * @param[in]   row     Row from which the queen is to be removed.
     * @return      Pointer to the created Remove_Queen_Command object.
     */
    virtual Remove_Queen_Command* create_remove_queen_command(Array<int> &board, int col) = 0;
};

#endif // _EXPR_COMMAND_FACTORY_H_
