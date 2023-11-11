// Expr_Command.h
//
// Abstract base class for all expression commands. 
// This class follows the Command Pattern to
//  - allow operations to be encapsulated as objects 
//      enabling easy extension and management of operations.

#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_

class Expr_Command {
    public:
    /** Execute the command.
     * 
     * This method must be overridden by derived command classes to perform
     *   their specific operations.
     *
     * @param s The stack to perform the operation on.
     * @throws std::exception If the operation cannot be performed.
     * @return returns a boolean whether or not the command execution was succesful or not
    */
    virtual void execute (void) = 0;
};

#endif   // !_EXPR_COMMAND_H_

