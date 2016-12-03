#include <iostream>
#include <Lexer/DexLexer.hpp>

void print_help();

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

    // Print output
    for (auto tok : output) {
        if (tok.token_type == DexTokenType::NUM) {
            cout << "<Number>";
        }
        cout << tok.token_value << endl;
    }
}

void print_help()
{
    cout << "Usage: dexc [expression]" << endl;
}