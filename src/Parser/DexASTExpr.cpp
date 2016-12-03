//
// Created by mafn on 12/3/16.
//

#include <iostream>
#include "DexASTExpr.hpp"

DexASTExpr::DexASTExpr(int num)
: type(DexASTExprType::AST_EXPR_NUM)
, left(nullptr)
, right(nullptr)
, value(num)
{
}

DexASTExpr::DexASTExpr(DexASTExprType type, DexASTExpr* left, DexASTExpr* right)
: type(type)
, left(left)
, right(right)
, value(-1)
{
}

void DexASTExpr::print()
{
    if (this->type == DexASTExprType::AST_EXPR_NUM) {
        std::cout << this->value << std::endl;
    } else {
        std::cout << DexAstExprTypeNames[(size_t)this->type] << " of:" << std::endl;
        this->left->print();
        std::cout << "and" << std::endl;
        this->right->print();
    }
}