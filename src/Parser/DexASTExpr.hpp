//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXASTEXPR_HPP
#define DUMBEXPRESSIONCOMPILER_DEXASTEXPR_HPP


#include "DexASTExprType.hpp"

class DexASTExpr {
public:
    DexASTExpr(DexASTExprType type, DexASTExpr* left, DexASTExpr* right);                           // For operators
    DexASTExpr(int num);                                                                            // For numbers

    // Always defined
    DexASTExprType type;
    DexASTExpr* left;
    DexASTExpr* right;

    // Not always defined
    int value;

    void print();
private:
};


#endif //DUMBEXPRESSIONCOMPILER_DEXASTEXPR_HPP
