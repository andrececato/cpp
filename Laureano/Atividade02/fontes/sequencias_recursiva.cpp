//sequencias_recursiva.cpp
#include <iostream>

int sequencia(int n)
{
    if( n == 1)
    {
        return 2;
    }
    else
    {
        return  2 * sequencia(n-1);
    }
}

int main()
{
    int n;
    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << sequencia(n) << std::endl;

    return 0;
}
