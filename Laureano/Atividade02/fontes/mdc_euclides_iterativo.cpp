//mdc_euclides_iterativo.cpp
#include <iostream>

int mdc(int m, int n)
{
    if( n == 0)
    {
        return m;
    }
    while( m % n != 0)
    {
        int resto = m % n;
        m = n;
        n = resto;
    }
    return n;

}

int main()
{
    int m,n;
    std::cout << "Digite o valor de m:" << std::endl;
    std::cin >> m;
    std::cout << "Digite o valor de n:" << std::endl;
    std::cin >> n;
    std::cout << "O MDC é: " << mdc(m,n) << std::endl;

    return 0;
}
