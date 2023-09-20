//triangular_iterativo.cpp
#include <iostream>

int triangular( int n )
{
   if( n == 1){
      return n;
   }
   return triangular(n-1) + n;
}

int main()
{
    int n;
    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << "O número Triangular é: " << triangular(n) << std::endl;

    return 0;
}
