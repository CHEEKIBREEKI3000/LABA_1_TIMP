#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;
bool isValid(const wstring& s)
{
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    int klych=3;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring z;
    wstring text;
    unsigned op;
    wcout<<L"Пожалуйста введите пароль: ";
    wcin>>z;
    Cipher cipher(klych);
    do {
        wcout<<L"Какую операцию необходимо произветси(0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
        if (isValid(text)) {
            if (op >0) {
            wcout<<L"Введите текст: ";
            wcin>>text;
                if (op==1) {
                    wcout<<L"Закодированный текст: "<<cipher.zakodirovatCipher(cipher, text)<<endl;
                } else {
                    wcout<<L"Раскодированный текст: "<<cipher.raskodirovatCipher(cipher, text)<<endl;
                }
                }else {
                wcout<<L"Operation aborted: invalid text\n";
                }
        }
    } while (op!=0);
    return 0;
}
