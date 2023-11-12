/**
 * @file       Concrete_Factory.cpp
 * @author     Tristan Kolat
 * 
 * @date       Nov 11th, 2023
 * @brief      Implements the Concrete_Factory class methods.
 */

#include "Concrete_Factory.h"
#include "Concrete_Command_Factory.h"
#include "Concrete_Query_Factory.h"

// Implementation of create_command_factory
Command_Factory* Concrete_Factory::create_command_factory() {
    return new Concrete_Command_Factory();
}

// Implementation of create_query_factory
Query_Factory* Concrete_Factory::create_query_factory() {
    return new Concrete_Query_Factory();
}
