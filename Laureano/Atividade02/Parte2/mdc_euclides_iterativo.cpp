//mdc_euclides_iterativo.cpp
#include <iostream>

int mdcI(int m, int n)
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

int mdcEuclidesIterativoMain(int m, int n)
{
    mdcI(m,n);
    //std::cout << "O MDC é: " << mdc(m,n) << std::endl;

    return 0;
}
