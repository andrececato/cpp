//mdc_euclides_recursivo.cpp
#include <iostream>

int mdc(int m, int n)
{
    if( m == n)
    {
        return m;
    }
    if( m-n >= n)
    {
        return mdc(m-n,n);
    }
    return mdc(n,m-n);
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
