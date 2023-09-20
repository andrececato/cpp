//sequencias_iterativa.cpp
#include <iostream>

int sequencia(int n)
{
    if( n == 1)
    {
        return 2;
    }
    else
    {
        int valorAtual=2;
        for(int i=2; i<n+1; ++i)
        {
            valorAtual *= 2;
        }
        return valorAtual;
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
