#include "funcoes.hpp"
#include <iostream>

using std::cout, std::cin, std::endl;
int pedir_ano(){
    int local_year;
    cout << "Ano desejado: ";
    cin >> local_year;
    return local_year;
}

void mostrar(int ano, bool resultado){
    cout << "Ano de " << ano << " ";
    if(resultado) cout << "é bissexto" << endl;
    if(!resultado) cout << "não bissexto" << endl;
}

bool div400(int numero){
    return numero % 400 == 0;
}

bool div4_not100(int numero){
    return numero % 4 == 0 && !(numero % 100 == 0);
}