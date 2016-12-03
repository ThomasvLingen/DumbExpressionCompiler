//
// Created by mafn on 12/3/16.
//

#ifndef DUMBEXPRESSIONCOMPILER_DEXPARSER_HPP
#define DUMBEXPRESSIONCOMPILER_DEXPARSER_HPP


#include <Lexer/DexLexer.hpp>
#include <algorithm>
#include "DexASTExpr.hpp"

class DexParser {
public:
    DexParser(LexOutput input);

    DexASTExpr* get_parsed_output();
private:
    LexOutput _input;
    DexASTExpr* _ast_root;

    void _parse();
    DexASTExpr* _parse_tokens(vector<DexToken> tokens);

    DexASTExpr* _parse_mult_div(vector<DexToken> tokens);
    DexASTExpr* _parse_add_sub(vector<DexToken> tokens);

    vector<vector<DexToken>> split(vector<DexToken>& tokens, vector<DexToken>::iterator to_split);
};


#endif //DUMBEXPRESSIONCOMPILER_DEXPARSER_HPP
