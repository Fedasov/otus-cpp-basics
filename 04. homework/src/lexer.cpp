// OTUS C++ Basic course homework skeleton.
// Lexer implementation

#include "lexer.hpp"

#include <cctype>

Lexer::Token Lexer::next_token() {
    for (;;) {
        std::cout << "lexer.cpp" << std::endl;
        switch (state_) {

        case State::End:
        std::cout << "State::End" << std::endl;
            return Token::End;

        case State::ReadNumber:
            std::cout << "State::ReadNumber" << std::endl;
            if (end()) {
                std::cout << "State::RedNumder end()" << std::endl;
                state_ = State::End;
                return Token::Number;
            }
            if (std::isdigit(ch_)) {
                std::cout << "State::ReadNumber" << std::endl;
                number_ = 10 * number_ + (ch_ - '0');
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            state_ = State::Empty;
            std::cout << "Vivodit token" << std::endl;
            return Token::Number;

        case State::ReadName:
            std::cout << "State::ReadName" << std::endl;
            if (end()) {
                state_ = State::End;
                return Token::Name;
            }
            if (std::isalpha(ch_) || std::isdigit(ch_)) {
                name_ += ch_;
                next_char();
                break;
            }
            state_ = State::Empty;
            return Token::Name;

        case State::Empty:
            std::cout << "State::Empty" << std::endl;
            if (end()) {
                state_ = State::End;
                return Token::End;
            }
            if (std::isspace(ch_)) {
                next_char();
                break;
            }
            if (isoperator(ch_)) {
                std::cout << "isoperator" << std::endl;
                operator_ = ch_;
                next_char();
                return Token::Operator;
            }
            if (ch_ == '(') {
                next_char();
                return Token::Lbrace;
            }
            if (ch_ == ')') {
                next_char();
                return Token::Rbrace;
            }
            if (std::isdigit(ch_)) {
                std::cout << "isdigit" <<std::endl;
                number_ = ch_ - '0';
                std::cout << number_ << std::endl;
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            if (std::isalpha(ch_)) {
                name_ = ch_;
                state_ = State::ReadName;
                next_char();
                break;
            }
        }
    }
}
