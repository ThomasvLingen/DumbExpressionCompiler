//
// Created by mafn on 12/24/16.
//

#include "DexAsmWriter.hpp"

void DexAsmWriter::write_assembly_file()
{
    std::ofstream out_file(this->_out_filename);

    if (out_file.is_open()) {
        // Use intel syntax (GCC / as)
        out_file << ".intel_syntax noprefix" << std::endl;
        this->_write_data(out_file);
        this->_write_text(out_file);
    }

    out_file.close();
}

void DexAsmWriter::_write_text(ofstream& out_file)
{
    out_file << std::endl << ".section .text" << std::endl;
    out_file << ".globl main" << std::endl;
    out_file << std::endl;
    out_file << "main:" << std::endl;

    for (string line : this->_text_section) {
        out_file << "    " << line << std::endl;
    }
}

void DexAsmWriter::_write_data(ofstream& out_file)
{
    out_file << std::endl << ".section .data" << std::endl;

    for (string line : this->_data_section) {
        out_file << "    " << line << std::endl;
    }
}

void DexAsmWriter::add_line(DexAsmLineType type, string line)
{
    if (type == DexAsmLineType::TEXT) {
        this->_text_section.push_back(line);
    }
    else if (type == DexAsmLineType::DATA) {
        this->_data_section.push_back(line);
    }
}
