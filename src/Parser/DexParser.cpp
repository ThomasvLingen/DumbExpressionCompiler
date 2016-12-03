//
// Created by mafn on 12/3/16.
//

#include "DexParser.hpp"

DexParser::DexParser(LexOutput input)
: _input(input)
{
    this->_parse();
}

void DexParser::_parse()
{
    this->_ast_root = this->_parse_tokens(this->_input);
}

DexASTExpr* DexParser::_parse_tokens(LexOutput tokens)
{
    // Base case, a single number!
    if (tokens.size() == 1 && tokens[0].token_type == DexTokenType::NUM) {
        return new DexASTExpr(tokens[0].token_value);
    }

    // The order in which the _parse_x functions are called determines the order of operations
    DexASTExpr* result = this->_parse_mult_div(tokens);
    if (result){
        return result;
    }
    else {
        return nullptr;
    }
}

vector<vector<DexToken>> DexParser::split(vector<DexToken>& tokens, vector<DexToken>::iterator to_split)
{
    vector<DexToken> before;
    vector<DexToken> after;

    // Get everything before token
    for (auto current_token = tokens.begin(); current_token != to_split; current_token++) {
        //long foo = std::distance(current_token, to_split);
        before.push_back(*current_token);
    }
    // Get everything after token
    for (auto current_token = std::next(to_split); current_token != tokens.end(); current_token++) {
        after.push_back(*current_token);
    }

    return {before, after};
}

DexASTExpr* DexParser::_parse_mult_div(vector<DexToken> tokens)
{
    LexOutput::iterator found_token = std::find_if(
        tokens.begin(), tokens.end(),
        [](DexToken tok){
            return tok.token_type == DexTokenType::OP_MULTIPLY or tok.token_type == DexTokenType::OP_DIVIDE;
        }
    );

    if (found_token == tokens.end()) {
        return nullptr;
    }

    // Hey, we've found a mult or div
    auto split_result = this->split(tokens, found_token);
    DexASTExpr* left = this->_parse_tokens(split_result[0]);
    DexASTExpr* right = this->_parse_tokens(split_result[1]);

    return new DexASTExpr(token_to_expr_type[(*found_token).token_type], left, right);
}

DexASTExpr* DexParser::get_parsed_output()
{
    return this->_ast_root;
}


