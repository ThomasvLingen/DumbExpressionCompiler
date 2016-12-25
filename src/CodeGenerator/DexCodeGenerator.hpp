//
// Created by mafn on 12/24/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXCODEGENERATOR_HPP
#define DUMBEXPRESSIONCOMPILER_DEXCODEGENERATOR_HPP


#include <Parser/DexASTExpr.hpp>
#include <AsmWriter/DexAsmWriter.hpp>

class DexCodeGenerator {
public:
    DexCodeGenerator(DexASTExpr* ast);
    void generate_code();
private:
    DexASTExpr* _ast;
    DexAsmWriter _code;

    void _traverse_node(DexASTExpr* node);

    bool _traverse_num(DexASTExpr* node);
    void _generate_num(DexASTExpr* node);

    bool _traverse_operator(DexASTExpr* node);
    void _generate_operator(DexASTExpr* node);
    void _generate_add(DexASTExpr* node);
    void _generate_sub(DexASTExpr* node);
    void _generate_mul(DexASTExpr* node);
    void _generate_div(DexASTExpr* node);
};


#endif //DUMBEXPRESSIONCOMPILER_DEXCODEGENERATOR_HPP
