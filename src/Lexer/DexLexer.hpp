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

    // Specific lex functions
    bool _lex_number();
};


#endif //DUMBEXPRESSIONCOMPILER_DEXLEXER_HPP
