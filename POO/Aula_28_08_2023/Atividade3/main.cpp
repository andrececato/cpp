#include <iostream>

using std::cout, std::endl;

int main() {
    int var = 5;
    int &teste = var;

    teste++;

    cout << "var=" << var << ", ";
    cout << "teste=" << teste << endl;

    cout << "&var=" << &var << ", ";
    cout << "&teste=" << &teste << endl;
}