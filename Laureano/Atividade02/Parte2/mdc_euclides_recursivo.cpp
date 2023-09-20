//mdc_euclides_recursivo.cpp
#include <iostream>

int mdcR(int m, int n)
{
    if( n == 0)
    {
        return m;
    }
    return mdc(n,m%n);

}

int mdcEuclidesRecursivoMain(int m, int n)
{
    mdcR(m,n);
    //std::cout << "O MDC é: " << mdc(m,n) << std::endl;

    return 0;
}
