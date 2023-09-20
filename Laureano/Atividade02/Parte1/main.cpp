#include <iostream>
#include "fibonacci_recursivo.hpp"
#include "fibonacci_iterativo.hpp"
#include <fstream>
#include <chrono>
#include <sys/resource.h>
#include <sstream>

using std::cout, std::endl, std::fstream, std::string;

void getCurrentTime(struct rusage r_usage, long double &userTime, long double &sysTime){
    getrusage(RUSAGE_SELF, &r_usage);
    userTime = (r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0)*1000;
    sysTime = (r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0)*1000;
}

void getCalcDurationTime(struct rusage r_usage, long double &startUserTime, long double &startSysTime, long double &durationUserTime, long double &durationSysTime){
    long double currentUserTime;
    long double currentSysTime;
    getCurrentTime(r_usage, currentUserTime, currentSysTime);
    durationUserTime = currentUserTime - startUserTime;
    durationSysTime = currentSysTime - startSysTime;
}

int main(){
    struct rusage r_usage;
    fstream File;
    File.open("data.csv");
    File << "iUserDurationTime;iSysDurationTime;rUserDurationTime;rSysDurationTime;memory";
    for(long int i = 0; i<500; i+=5){
        string line = "";
        long double startUserTimeI;
        long double startSysTimeI;
        getCurrentTime(r_usage, startUserTimeI, startSysTimeI);

        //auto start = high_resolution_clock::now();
        fibonnaciIMain(i);
        //auto stop = high_resolution_clock::now();
        //nanoseconds duracao1 = duration_cast<nanoseconds>(stop - start);
        
        //auto start2 = high_resolution_clock::now();
        long double durationUserTimeI;
        long double durationSysTimeI;
        getCalcDurationTime(r_usage, startUserTimeI, startSysTimeI, durationUserTimeI, durationSysTimeI);
        cout << "Iterativo " << i << " - tempo usuário: " << durationUserTimeI << "ms - tempo sistema: " << durationSysTimeI << "ms"<< endl;

        long double startUserTimeR;
        long double startSysTimeR;
        getCurrentTime(r_usage, startUserTimeR, startSysTimeR);
        fibonnaciRMain(i);
        //auto stop2 = high_resolution_clock::now();
        //nanoseconds duracao2 = duration_cast<nanoseconds>(stop2 - start2);
        
        //cout << "Iterativo: " << duracao1.count()/1000.0 << "ms" << endl;
        //cout << "Recursivo: " << duracao2.count()/1000.0 << "ms" << endl;
        long double durationUserTimeR;
        long double durationSysTimeR;
        getCalcDurationTime(r_usage, startUserTimeR, startSysTimeR, durationUserTimeR, durationSysTimeR);
        cout << "Recursivo " << i << " - tempo usuário: " << durationUserTimeR << "ms - tempo sistema: " << durationSysTimeR << "ms"<< endl;
        
        getrusage(RUSAGE_SELF, &r_usage);
        cout << "Memória usada: " << r_usage.ru_maxrss << endl << endl;

        File << durationUserTimeI << ";" << durationSysTimeI << ";" << durationUserTimeR << ";" << durationSysTimeR << ";" << r_usage.ru_maxrss << endl;
        
    }
    File.close();
    cout << "Terminou!!!";
}