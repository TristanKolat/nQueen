// Expr_Query.h
/**
 * @file Expr_Query.h
 * @author Tristan Kolat
 * 
 * @date Nov 11th, 2023
 * @brief Abstract base class for expression queries.
 *
 * This file defines the interface for expression queries within the application.
 * Queries are used for operations that return information without changing
 * the state of the system. Each derived query class should override the
 * execute method to perform its specific operation and return a boolean result.
 */

#ifndef _EXPR_QUERY_H_
#define _EXPR_QUERY_H_

class Expr_Query {
public:
    /// Virtual destructor for base class
    virtual ~Expr_Query() { }

    /**
     * Execute the query.
     * 
     * This method must be overridden by derived query classes to perform
     * their specific operations and return a boolean result indicating
     * the outcome of the query.
     * 
     * @return true if the query condition is met, false otherwise.
     */
    virtual bool execute() = 0;
};

#endif // !_EXPR_QUERY_H_
