//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXASTEXPRTYPE_HPP
#define DUMBEXPRESSIONCOMPILER_DEXASTEXPRTYPE_HPP

#include <map>
#include <string>
#include <Lexer/DexTokenType.hpp>

enum class DexASTExprType
{
    AST_EXPR_NUM,
    AST_EXPR_ADD,
    AST_EXPR_SUBSTRACT,
    AST_EXPR_MULTIPLY,
    AST_EXPR_DIVIDE
};

extern std::string DexAstExprTypeNames[];

extern std::map<DexTokenType, DexASTExprType> token_to_expr_type;

#endif //DUMBEXPRESSIONCOMPILER_DEXASTEXPRTYPE_HPP
