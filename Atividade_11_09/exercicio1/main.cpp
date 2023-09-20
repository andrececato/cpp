#include <iostream>

using std::cout, std::cin, std::endl;

void getTime(int InputMin, int &min, int &hour){
    hour = (int)(InputMin/60);
    min = InputMin%60;    
}

int main(){
    int InputMin, min, hour;
    cout << "Digite os minutos: ";
    cin >> InputMin;
    getTime(InputMin, min, hour);
    cout << endl << hour << " horas e " << min << " minutos" << endl;   
    
}