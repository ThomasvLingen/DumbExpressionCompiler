//
// Created by mafn on 12/24/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXASMWRITER_HPP
#define DUMBEXPRESSIONCOMPILER_DEXASMWRITER_HPP

#include <string>
#include <vector>
#include <fstream>

using std::vector;
using std::string;
using std::ofstream;

enum class DexAsmLineType
{
    TEXT,
    DATA
};

class DexAsmWriter {
public:
    void add_line(DexAsmLineType type, string line);
    void write_assembly_file();
private:
    const string _out_filename = "out.asm";

    vector<string> _text_section;
    vector<string> _data_section;

    void _write_text(ofstream& out_file);
    void _write_data(ofstream& out_file);
};


#endif //DUMBEXPRESSIONCOMPILER_DEXASMWRITER_HPP
