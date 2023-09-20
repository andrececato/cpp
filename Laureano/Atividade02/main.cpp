#include <iostream>
#include "fibonacci_recursivo.hpp"
#include "fibonacci_iterativo.hpp"
#include <fstream>
#include <chrono>
#include <sys/resource.h>
#include <sstream>

using std::cout, std::endl, std::fstream, std::string;

void getCurrentTime(struct rusage r_usage, double &userTime, double &sysTime){
    getrusage(RUSAGE_SELF, &r_usage);
    userTime = (r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0)*1000000;
    sysTime = (r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0)*1000000;
}

void getCalcDurationTime(struct rusage r_usage, double &startUserTime, double &startSysTime, double &durationUserTime, double &durationSysTime){
    double currentUserTime;
    double currentSysTime;
    getCurrentTime(r_usage, currentUserTime, currentSysTime);
    durationUserTime = currentUserTime - startUserTime;
    durationSysTime = currentSysTime - startSysTime;
}

int main(){
    struct rusage r_usage;
    fstream File("data.csv");
    File << "iUserDurationTime;iSysDurationTime;rUserDurationTime;rSysDurationTime;memory";
    for(long long int i = 0; i<500; i+=5){
        string line = "";
        double startUserTime;
        double startSysTime;
        getCurrentTime(r_usage, startUserTime, startSysTime);

        //auto start = high_resolution_clock::now();
        fibonnaciIMain(i);
        //auto stop = high_resolution_clock::now();
        //nanoseconds duracao1 = duration_cast<nanoseconds>(stop - start);
        
        //auto start2 = high_resolution_clock::now();
        double durationUserTime;
        double durationSysTime;
        getCalcDurationTime(r_usage, startUserTime, startSysTime, durationUserTime, durationSysTime);
        cout << "Iterativo " << i << " - tempo usuário: " << durationUserTime << "ms - tempo sistema: " << durationSysTime << "ms"<< endl;

        getCurrentTime(r_usage, startUserTime, startSysTime);
        fibonnaciRMain(i);
        //auto stop2 = high_resolution_clock::now();
        //nanoseconds duracao2 = duration_cast<nanoseconds>(stop2 - start2);
        
        //cout << "Iterativo: " << duracao1.count()/1000.0 << "ms" << endl;
        //cout << "Recursivo: " << duracao2.count()/1000.0 << "ms" << endl;
        durationUserTime;
        durationSysTime;
        getCalcDurationTime(r_usage, startUserTime, startSysTime, durationUserTime, durationSysTime);
        cout << "Recursivo " << i << " - tempo usuário: " << durationUserTime << "ms - tempo sistema: " << durationSysTime << "ms"<< endl;
        
        getrusage(RUSAGE_SELF, &r_usage);
        cout << "Memória usada: " << r_usage.ru_maxrss << endl << endl;
        
    }
    cout << "Terminou!!!";
}