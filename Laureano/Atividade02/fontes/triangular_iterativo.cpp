//triangular_iterativo.cpp
#include <iostream>

int triangular( int n )
{
   int total = 0;
   while( n>0 ){
      total += n;
      --n;
   }
   return total;
}

int main()
{
    int n;
    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << "O número Triangular é: " << triangular(n) << std::endl;

    return 0;
}
