#include "parser.hpp"
#include "number.hpp"
#include "variable.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mul.hpp"
#include "div.hpp"

#include <iostream>


using namespace std;

using Token = Lexer::Token;

ASTNode *Parser::parse() { return expr(); }

void Parser::next_token() { tok_ = lexer_.next_token(); }

ASTNode *Parser::expr() {
    // parse addition and subsctruction
    ASTNode *root = term();
    cout << "expr" << endl;
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                // Implement Add class and uncomment this line
                cout << "Add +" << endl;
                root = new Add(root, term());
                break;
            case '-':
                // Implement Sub class and uncomment this line
                root = new Sub(root, term());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::term() {
    // parse multiplication and division
    ASTNode *root = prim();
    cout << "term" << endl;
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '*':
                // Implement Mul class and uncomment this line
                root = new Mul(root, prim());
                break;
            case '/':
                // Implement Div class and uncomment this line
                root = new Div(root, prim());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}


ASTNode *Parser::prim() {
    // parse numbers and names
    cout << "prim" << endl;
    ASTNode *node = nullptr;
    next_token();
    switch (tok_) {
    case Token::Number: 
        cout << "prim Number" << endl;
        node = new Number(lexer_.get_number());
        cout << "node" << endl;
        break;
    case Token::Name:
        // Implement Variable class and uncomment this line
        node = new Variable(lexer_.get_name());
        break;
    default:
        break;
    }
    next_token();
    cout << "prim end" << endl; 
    return node;
}