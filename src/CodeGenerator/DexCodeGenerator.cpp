//
// Created by mafn on 12/24/16.
//

#include <iostream>
#include "DexCodeGenerator.hpp"

DexCodeGenerator::DexCodeGenerator(DexASTExpr* ast)
: _ast(ast)
{

}

void DexCodeGenerator::generate_code()
{
    this->_traverse_node(this->_ast);

    // Add code to put result in status code (return value) of program
    this->_code.add_line(DexAsmLineType::TEXT, "MOV EAX, 1 # sys_exit call");
    this->_code.add_line(DexAsmLineType::TEXT, "POP EBX    # put result in EBX (status_code)");
    this->_code.add_line(DexAsmLineType::TEXT, "INT 0x80   # interrupt");

    this->_code.write_assembly_file();
}

// This traverses the nodes post order
void DexCodeGenerator::_traverse_node(DexASTExpr* node)
{
    if (this->_traverse_num(node)) {}
    else if (this->_traverse_operator(node)) {}
    else {
        // We don't recognise this node type, so we skip it
    }
}

bool DexCodeGenerator::_traverse_num(DexASTExpr* node)
{
    if (node->type == DexASTExprType::AST_EXPR_NUM) {
        this->_generate_num(node);

        return true;
    }

    return false;
}

bool DexCodeGenerator::_traverse_operator(DexASTExpr* node)
{
    if (node->type == DexASTExprType::AST_EXPR_ADD ||
        node->type == DexASTExprType::AST_EXPR_SUBSTRACT ||
        node->type == DexASTExprType::AST_EXPR_DIVIDE ||
        node->type == DexASTExprType::AST_EXPR_MULTIPLY)
    {
        this->_traverse_node(node->left);
        this->_traverse_node(node->right);
        this->_generate_operator(node);

        return true;
    }

    return false;
}

void DexCodeGenerator::_generate_num(DexASTExpr* node)
{
    std::cout << "[CODEGEN] " << node->value << std::endl;

    this->_code.add_line(DexAsmLineType::TEXT, "PUSH " + std::to_string(node->value));
}

void DexCodeGenerator::_generate_operator(DexASTExpr* node)
{
    // TODO: This is ugly and stupid, should probably made a map<DexASTExprType, DexCodeGenerator::*code_gen_func>
    switch (node->type) {
        case DexASTExprType::AST_EXPR_ADD:
            this->_generate_add(node);
            break;
        case DexASTExprType::AST_EXPR_SUBSTRACT:
            this->_generate_sub(node);
            break;
        case DexASTExprType::AST_EXPR_MULTIPLY:
            this->_generate_mul(node);
            break;
        case DexASTExprType::AST_EXPR_DIVIDE:
            this->_generate_div(node);
        default:
            // We don't recognise this operator type, so we skip it
            break;
    }
}

void DexCodeGenerator::_generate_add(DexASTExpr* node)
{
    std::cout << "[CODEGEN] ADD" << std::endl;

    this->_code.add_line(DexAsmLineType::TEXT, "POP EAX");
    this->_code.add_line(DexAsmLineType::TEXT, "POP EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "ADD EAX, EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "PUSH EAX");
}

void DexCodeGenerator::_generate_sub(DexASTExpr* node)
{
    std::cout << "[CODEGEN] SUB" << std::endl;

    this->_code.add_line(DexAsmLineType::TEXT, "POP EAX");
    this->_code.add_line(DexAsmLineType::TEXT, "POP EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "SUB EAX, EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "PUSH EAX");
}

void DexCodeGenerator::_generate_mul(DexASTExpr* node)
{
    std::cout << "[CODEGEN] MUL" << std::endl;

    this->_code.add_line(DexAsmLineType::TEXT, "POP EAX");
    this->_code.add_line(DexAsmLineType::TEXT, "POP EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "IMUL EAX, EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "PUSH EAX");
}

void DexCodeGenerator::_generate_div(DexASTExpr* node)
{
    std::cout << "[CODEGEN] DIV" << std::endl;

    // IDIV divides EDX:EAX by the operand
    // So since the stack looks like [numerator divident] we first pop EBX and then EAX
    // Then IDIV by EBX (divident)
    this->_code.add_line(DexAsmLineType::TEXT, "POP EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "POP EAX");
    this->_code.add_line(DexAsmLineType::TEXT, "IDIV EBX");
    this->_code.add_line(DexAsmLineType::TEXT, "PUSH EAX");
}
