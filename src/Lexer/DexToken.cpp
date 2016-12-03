//
// Created by mafn on 12/3/16.
//

#include "DexToken.hpp"

void DexToken::print()
{
    cout << DexTokenTypeNames[(size_t)this->token_type];
    if (this->token_type == DexTokenType::NUM) {
        cout << " " << this->token_value;
    }
    cout << endl;
}
