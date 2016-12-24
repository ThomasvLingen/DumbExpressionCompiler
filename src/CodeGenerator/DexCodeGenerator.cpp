//
// Created by mafn on 12/24/16.
//

#include "DexCodeGenerator.hpp"

DexCodeGenerator::DexCodeGenerator(DexASTExpr* ast)
: _ast(ast)
{

}

void DexCodeGenerator::generate_code()
{
    this->_code.add_line(DexAsmLineType::TEXT, "pop eax");
    this->_code.write_assembly_file();
}
