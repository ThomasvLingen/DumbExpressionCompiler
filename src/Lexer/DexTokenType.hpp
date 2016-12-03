//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXTOKENS_HPP
#define DUMBEXPRESSIONCOMPILER_DEXTOKENS_HPP

#include <string>

enum class DexTokenType
{
    NUM,
    OP_ADD,
    OP_SUBSTRACT,
    OP_MULTIPLY,
    OP_DIVIDE
};

extern std::string DexTokenTypeNames[];

#endif //DUMBEXPRESSIONCOMPILER_DEXTOKENS_HPP
