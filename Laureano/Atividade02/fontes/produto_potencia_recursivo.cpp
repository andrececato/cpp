//produto_potencia_recursivo.cpp
#include <iostream>

// Cálculo do produto
int produto( int m, int n)
{
    if( n == 1 )
    {
        return m;
    }
    return produto(m,n-1) + m;
}

// Cálculo da potência
int potencia(int m, int n)
{
    if( n == 0)
    {
        return 1;
    }
    return potencia(m,n-1) * m;
}

int main()
{
    int n,m;
    std::cout << "Digite o valor de m:" << std::endl;
    std::cin >> m;

    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << "Produto:" << produto(m,n) << std::endl;
    std::cout << "Potência:" << potencia(m,n) << std::endl;

    return 0;
}
