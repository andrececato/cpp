//fatorial_iterativo.cpp
#include <iostream>

// Versão recursiva
int fatorial( int n )
{
   if( n == 1 ){ // Condição de parada
      return 1;
   }
   return n * fatorial(n-1);
}

int main()
{
    int n;
    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << "Fatorial é:" << fatorial(n) << std::endl;

    return 0;
}
