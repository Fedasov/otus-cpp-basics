#include "parser.hpp"
#include "number.hpp"
#include "variable.hpp"
#include "add.hpp"

using Token = Lexer::Token;
using namespace std;

ASTNode *Parser::parse() { return expr(); }

void Parser::next_token() { 
    cout << "parser" << endl;
    tok_ = lexer_.next_token(); 
    cout << "next_token konec" << endl << endl;
    }

ASTNode *Parser::expr() {
    // parse addition and subsctruction
    ASTNode *root = term();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                cout << "ch_ okazalos +" << endl;
                // Implement Add class and uncomment this line
                cout << root << endl;
                // root = new Add(root, term());

                break;
                //return root;
            case '-':
                // Implement Sub class and uncomment this line
                //root = new Sub(root, term());
                return nullptr;
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
    cout << " _______ "<< endl;
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            cout << "zdes" << endl;
            std::string op = lexer_.get_operator();
            cout << op << endl;
            switch (op.front()) {
            case '*':
                // Implement Mul class and uncomment this line
                // root = new Mul(root, prim());
                return nullptr;
                break;
            case '/':
                // Implement Div class and uncomment this line
                //root = new Div(root, prim());
                return nullptr;
                break;
            default:
                cout << "defoult" << endl;
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
    ASTNode *node = nullptr;
    cout << "popal v prim" << endl << endl;
    next_token();
    switch (tok_) {
    case Token::Number:
        cout << "Popal v prim Token::Number" << endl;
        node = new Number(lexer_.get_number());
        cout << node<< endl;
        break;
    case Token::Name:
        // Implement Variable class and uncomment this line
        node = new Variable(lexer_.get_name());
        break;
    default:
        break;
    }
    next_token();
    cout << node<< endl;
    return node;
}