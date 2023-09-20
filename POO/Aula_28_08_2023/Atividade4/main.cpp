#include <iostream>

using std::cout, std::endl;

int main() {
   int var = 5;
   int *teste = &var;

   cout << "var=" << var << ", ";
   cout << "teste=" << teste << endl;

   cout << "&var=" << &var << ", ";
   cout << "&teste=" << &teste << endl;

   cout << "*teste=" << *teste << endl;
}
