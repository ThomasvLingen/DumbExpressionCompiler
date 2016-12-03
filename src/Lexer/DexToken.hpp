//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP
#define DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP

#include <Lexer/DexTokenType.hpp>
#include <iostream>

using std::cout;
using std::endl;

struct DexToken {
    DexToken(DexTokenType type, int value)
    : token_type(type)
    , token_value(value)
    {
    }

    DexToken(DexTokenType type)
    : token_type(type)
    , token_value(-1)
    {
    }

    DexTokenType token_type;
    int token_value;

    void print();
};


#endif //DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP
