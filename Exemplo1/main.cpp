#include <iostream>

using std::cout, std::cin, std::endl;

void tabuada(int x){
    int result = 0;
    for(int i = 0; i<=10; i++){
        result = x * i;
        cout << x << " x " << i;
        cout << " = " << result << endl;
    }
}

int pede_valor(){
    int num = 0;
    cout << "Digite um numero: ";
    cin >> num;
    return num;
}

int main(){
    int valor;
    valor = pede_valor();
    tabuada(valor);
}