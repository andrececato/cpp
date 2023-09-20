//fibonnaci_iterativo.cpp
#include <iostream>

int fibonnaciI(int n){
   if( n<=2 ){
      return 1;
   }
   int n1 = 1; // 1 Termo
   int n2 = 1; // 2 Termo
   for(int i=2; i<n; ++i){
      int anterior = n1;
      n1 = n2;
      n2 = anterior + n1;
   }
   return n2;
}

int fibonnaciIMain(int n)
{
   //std::cout << "O número de Fibonnaci é: " << fibonnaciI(n) << std::endl;

   return 0;
}
