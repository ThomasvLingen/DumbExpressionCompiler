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
};


#endif //DUMBEXPRESSIONCOMPILER_DEXCODEGENERATOR_HPP
