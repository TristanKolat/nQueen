/**
 * @file Concrete_Expr_Command_Factory.h
 * @author Tristan Kolat
 * 
 * @date Nov 11th, 2023
 * 
 * @brief Concrete factory for creating command objects related to placing and removing queens in the N-Queens problem.
 */

#ifndef _CONCRETE_EXPR_COMMAND_FACTORY_H_
#define _CONCRETE_EXPR_COMMAND_FACTORY_H_

#include "Interface/Expr_Command_Factory.h"
#include "../../Iterator/iterArray/Array_Iterator.h"

/**
 * @class Concrete_Expr_Command_Factory
 * @brief Concrete factory for creating command objects.
 *
 * Implements Expr_Command_Factory to provide concrete command objects for the N-Queens problem.
 */
class Concrete_Expr_Command_Factory : public Expr_Command_Factory {
public:
    virtual Place_Queen_Command* create_place_queen_command(Array<int> &board, int col, int row);
    virtual Remove_Queen_Command* create_remove_queen_command(Array<int> &board, int col);
};

#endif // _CONCRETE_EXPR_COMMAND_FACTORY_H_
