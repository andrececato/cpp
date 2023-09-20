#include <iostream>
#include "funcoes.hpp"

using std::cout;

bool verifica_bissexto(int ano) {
    bool ret = false;
    if( div400(ano) or div4_not100(ano) ) 
    ret = true;
    return ret;
}

int main () {
    int ano = pedir_ano();
    bool result = verifica_bissexto(ano);
    mostrar(ano, result);
}
