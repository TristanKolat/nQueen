/**
 * @file       Concrete_Factory.h
 * @author     Tristan Kolat
 * 
 * @date       Nov 11th, 2023
 * @brief      Concrete implementation of Abstract_Factory to create command and query objects.
 */

#ifndef _CONCRETE_FACTORY_H_
#define _CONCRETE_FACTORY_H_

#include "Interface/Abstract_Factory.h"

#include "../Cmd_Factory/Concrete_Expr_Command_Factory.h"
#include "../Query_Factory/Concrete_Expr_Query_Factory.h"

/**
 * @brief Concrete implementation of the Abstract_Factory interface.
 *
 * This factory is responsible for creating concrete command and query objects.
 */
class Concrete_Factory : public Abstract_Factory {
public:
    /**
     * Retrieves a concrete command factory object.
     * @return  A new instance of a command factory.
     */
    virtual Expr_Command_Factory* create_command_factory();

    /**
     * Retrieves a concrete query factory object.
     * @return  A new instance of a query factory.
     */
    virtual Expr_Query_Factory* create_query_factory();
};

#endif // _CONCRETE_FACTORY_H_
