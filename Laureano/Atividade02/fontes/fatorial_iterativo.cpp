//fatorial_iterativo.cpp
#include <iostream>

int fatorial( int n )
{
    int f = 1;
    for( int i = 1; i<n; ++i )
    {
        f += f*i;
    }
    return f;
}

int main()
{
    int n;
    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << "Fatorial é:" << fatorial(n) << std::endl;

    return 0;
}
