/**
 * @file       Abstract_Factory.h
 * @author     Tristan Kolat
 * 
 * @date       Nov 11th, 2023
 * @brief      Abstract factory for creating command and query objects.
 */

#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include "../../Query_Factory/Interface/Expr_Query_Factory.h"
#include "Expr_Query_Factory.h"

/**
 * @class Abstract_Factory
 * @brief Abstract factory Interface for generating families of commands and queries.
 */
class Abstract_Factory {
public:
    virtual ~Abstract_Factory() {}

    /** virtual command factory
     * 
     * concrete will create the command factory object.
     * @return  A pointer to the command factory.
     */
    virtual Command_Factory* create_command_factory() = 0;

    /** virtual query factory
     * 
     * Cocrete will create the query factory object.
     * @return  A pointer to the query factory.
     */
    virtual Query_Factory* create_query_factory() = 0;
};

#endif // _ABSTRACT_FACTORY_H_

