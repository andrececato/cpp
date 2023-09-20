//fibonnaci_iterativo.cpp
#include <iostream>

int fibonnaci(int n){
   if( n <= 2){
      return 1;
   }
   return( fibonnaci(n-1)) + fibonnaci(n-2); // Chama 2 vezes!!!!
}

int main()
{
    int n;
    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << "O número de Fibonnaci é: " << fibonnaci(n) << std::endl;

    return 0;
}
