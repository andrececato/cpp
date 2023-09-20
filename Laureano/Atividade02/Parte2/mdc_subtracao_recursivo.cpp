//mdc_euclides_recursivo.cpp
#include <iostream>

int mdcS(int m, int n)
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

int mdcEuclidesSubtracaoMain()
{
    mdcS(m,n);
    //std::cout << "O MDC é: " << mdcS(m,n) << std::endl;

    return 0;
}
