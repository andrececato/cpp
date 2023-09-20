#include <iostream>

using std::cout, std::cin, std::endl;

void getTime(int InputMin, int &min, int &hour, int &day){
    hour = (int)(InputMin/60);
    day = (int)hour/24;
    hour = hour%24;
    min = InputMin%60;
}

int main(){
    int InputMin, min, hour, day;
    cout << "Digite os minutos: ";
    cin >> InputMin;
    getTime(InputMin, min, hour, day);
    cout << endl << day << " dias, " << hour << " horas e " << min << " minutos" << endl;   
    
}