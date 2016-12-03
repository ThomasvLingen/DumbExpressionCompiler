//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP
#define DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP

#include <Lexer/DexTokenType.hpp>

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
};


#endif //DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP
