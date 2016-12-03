//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXLEXER_HPP
#define DUMBEXPRESSIONCOMPILER_DEXLEXER_HPP


#include <vector>
#include <string>
#include "DexToken.hpp"

using std::string;
using std::vector;

typedef vector<DexToken> LexOutput;

class DexLexer {
public:
    DexLexer(string input);

    LexOutput get_lexed_output();
private:
    string _input;
    LexOutput _output;

    string::iterator _current_char;

    void _lex();
    void _consume_character();
    void _add_token(DexToken to_add);

    // Specific lex functions
    bool _lex_number();
    bool _lex_operator_add();
    bool _lex_operator_substract();
    bool _lex_operator_multiply();
    bool _lex_operator_divide();
};


#endif //DUMBEXPRESSIONCOMPILER_DEXLEXER_HPP
