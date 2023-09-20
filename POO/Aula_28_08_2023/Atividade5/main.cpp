#include <iostream>

using std::cout, std::endl;

void myprint(int var, int* teste) {
   cout << "var=" << var << ", ";
   cout << "teste=" << teste << endl;

   cout << "&var=" << &var << ", ";
   cout << "&teste=" << &teste << endl;

   cout << "*teste=" << *teste << endl;
   cout << "---" << endl;
}

void test_ponteiro2() {
   int var = 5;
   int *teste = &var;

   myprint(var, teste);
   *teste = *teste + 1;
   myprint(var, teste);
   teste = teste + 1;
   myprint(var, teste);
}

int main(){
   test_ponteiro2();
}