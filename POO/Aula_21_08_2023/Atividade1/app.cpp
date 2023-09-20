#include <iostream>
#include "func.hpp"

using std::string, std::cout, std::cin, std::getline, std::endl;

int main(){
    string nome;
    cout << "Bom dia!!!" << endl;
    nome = StringPedirNome();
    cout << "Seu nome é " << nome << endl;
}