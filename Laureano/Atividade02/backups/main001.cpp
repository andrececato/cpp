#include <iostream>
#include "fibonacci_recursivo.hpp"
#include "fibonacci_iterativo.hpp"
#include <chrono>
#include <sys/resource.h>

using namespace std;
using namespace chrono;

int main(){
    struct rusage r_usage;
    for(long long int i = 0; i<500; i+=5){
        auto start = high_resolution_clock::now();
        fibonnaciIMain(i);
        auto stop = high_resolution_clock::now();
        nanoseconds duracao1 = duration_cast<nanoseconds>(stop - start);
        
        auto start2 = high_resolution_clock::now();
        fibonnaciRMain(i);
        auto stop2 = high_resolution_clock::now();
        nanoseconds duracao2 = duration_cast<nanoseconds>(stop2 - start2);

        cout << "Iterativo: " << duracao1.count()/1000.0 << "ms" << endl;
        cout << "Recursivo: " << duracao2.count()/1000.0 << "ms" << endl;
    }
    cout << "Terminou!!!";
}