//
// Created by mafn on 12/3/16.
//

#include "DexLexer.hpp"

DexLexer::DexLexer(string input)
: _input(input)
, _current_char(this->_input.begin())
{
    this->_lex();
}

void DexLexer::_lex()
{
    while (this->_current_char != this->_input.end()) {
        if (this->_lex_number()) {}
        else {
            // We reach this statement when no lex functions could lex the current token
            // We just skip the token in that case
            this->_consume_character();
        }
    }
}

vector<DexToken> DexLexer::get_lexed_output()
{
    return this->_output;
}

void DexLexer::_consume_character()
{
    this->_current_char++;
}

bool DexLexer::_lex_number()
{
    // Are we dealing with a number?
    if (isdigit(*this->_current_char)) {
        string number_string = "";

        // Extract digits into a string while we encounter numbers
        while (isdigit(*this->_current_char)) {
            number_string += *this->_current_char;

            this->_consume_character();
        }

        this->_output.push_back(DexToken {DexTokenType::NUM, std::stoi(number_string)});
        return true;
    }

    return false;
}
