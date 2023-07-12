#pragma once
#include "astnode.hpp"
#include <string>
#include "parser.h"

class Add : public ASTNode {
    public: 
        Add (ASTNode *lhs, ASTNode *rhs) 
        : ASTNode ("+", lhs, rhs) {};
};