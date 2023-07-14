// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

int main() {
    // TODO
    // Implement the next classes:
    // Add
    // Sub
    // Mul
    // Div
    // Variable

    // Without implementation that classes this application works only with numbers
    std::cout << "Write primer" << std::endl;

    Lexer lexer(std::cin);
    std::cout <<"main"<< std::endl;
    Parser parser(lexer);

    ASTNode *ast = parser.parse();
    std::cout << ast << std::endl;
    if (ast) {
         ast->print(std::cout);
    }

    return 0;
}
