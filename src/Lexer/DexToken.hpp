//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP
#define DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP

#include <Lexer/DexTokenType.hpp>

struct DexToken {
    DexTokenType token_type;
    int token_value;
};


#endif //DUMBEXPRESSIONCOMPILER_DEXTOKEN_HPP
