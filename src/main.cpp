#include <iostream>
#include <Lexer/DexLexer.hpp>
#include <Parser/DexParser.hpp>

void print_help();

void print_lex_output(LexOutput& output);
void print_parse_output(DexASTExpr* ast_root);

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    cout << "Hi" << endl;

    if (argc != 2) {
        print_help();

        return 0;
    }

    std::string to_lex(argv[1]);

    // Lex input
    DexLexer lexer(to_lex);
    LexOutput output = lexer.get_lexed_output();
    print_lex_output(output);

    // Parse lex output (build AST)
    DexParser parser(output);
    DexASTExpr* ast = parser.get_parsed_output();
    print_parse_output(ast);
}

void print_help()
{
    cout << "Usage: dexc [expression]" << endl;
}

void print_lex_output(LexOutput& output)
{
    cout << "Lex output: " << endl;
    for (auto tok : output) {
        tok.print();
    }
    cout << endl;
}

void print_parse_output(DexASTExpr* ast_root)
{
    cout << "Parser output:" << endl;
    ast_root->print();
    cout << endl;
}