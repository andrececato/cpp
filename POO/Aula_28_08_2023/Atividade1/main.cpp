#include <iostream>
#include <cstdlib>

using std::cout, std::endl, std::string;

int main(){
    srand((unsigned) time(NULL));
    int cont = 0;
    int cont_more = 0;
    int cont_less = 0;
    string type = "normal";
    while(cont<500){
        cont++;
        int number = rand()%51;
        cout << "Número: " << number << endl;
        if(number == 0){
            continue;
        }
        if(number == 25){ 
            cout << "Continuando" << endl;
            type = "break";
            break;
        }
        if(number < 25) cont_less += 1;
        if(number > 25) cont_more += 1;
    }
    if(cont == 500){
        cout << "Igual a 500, saindo";
    }
    cout << "Quantidade total: " << cont << endl;
    cout << "Quantidade maiores: " << cont_more << endl;
    cout << "Quantidade menores: " << cont_less << endl;
    cout << "Saiu: " << type << endl;
}