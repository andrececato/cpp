//fibonnaci_iterativo.cpp
#include <iostream>

int fibonnaciR(int n){
   if( n <= 2){
      return 1;
   }
   return( fibonnaciR(n-1)) + fibonnaciR(n-2); // Chama 2 vezes!!!!
}

int fibonnaciRMain(int n)
{
   //std::cout << "O número de Fibonnaci é: " << fibonnaciR(n) << std::endl;

   return 0;
}
