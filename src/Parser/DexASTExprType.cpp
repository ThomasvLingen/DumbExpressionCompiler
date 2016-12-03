//
// Created by mafn on 12/3/16.
//

#include "DexASTExprType.hpp"

std::string DexAstExprTypeNames[] =
{
    "Number",
    "Addition",
    "Substraction",
    "Multiplication",
    "Division"
};

std::map<DexTokenType, DexASTExprType> token_to_expr_type = {
    {DexTokenType::NUM, DexASTExprType::AST_EXPR_NUM},
    {DexTokenType::OP_ADD, DexASTExprType::AST_EXPR_ADD},
    {DexTokenType::OP_SUBSTRACT, DexASTExprType::AST_EXPR_SUBSTRACT},
    {DexTokenType::OP_MULTIPLY, DexASTExprType::AST_EXPR_MULTIPLY},
    {DexTokenType::OP_DIVIDE, DexASTExprType::AST_EXPR_DIVIDE}
};
