#include <iostream>
#include "mdc_euclides_iterativo.hpp"
#include "mdc_euclides_recursivo.hpp"
#include "mdc_subtracao_recursivo.hpp"
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
        mdcEuclidesIterativoMain(); //Alterar
        long double durationUserTimeI;
        long double durationSysTimeI;
        getCalcDurationTime(r_usage, startUserTimeI, startSysTimeI, durationUserTimeI, durationSysTimeI);
        cout << "Iterativo " << i << " - tempo usuário: " << durationUserTimeI << "ms - tempo sistema: " << durationSysTimeI << "ms"<< endl;

        long double startUserTimeR;
        long double startSysTimeR;
        getCurrentTime(r_usage, startUserTimeR, startSysTimeR);
        mdcEuclidesRecursivoMain(); //Alterar
        long double durationUserTimeR;
        long double durationSysTimeR;
        getCalcDurationTime(r_usage, startUserTimeR, startSysTimeR, durationUserTimeR, durationSysTimeR);
        cout << "Recursivo " << i << " - tempo usuário: " << durationUserTimeR << "ms - tempo sistema: " << durationSysTimeR << "ms"<< endl;

        long double startUserTimeS;
        long double startSysTimeS;
        getCurrentTime(r_usage, startUserTimeS, startSysTimeS);
        mdcEuclidesSubtracaoMain(); //Alterar
        long double durationUserTimeS;
        long double durationSysTimeS;
        getCalcDurationTime(r_usage, startUserTimeS, startSysTimeS, durationUserTimeS, durationSysTimeS);
        cout << "Recursivo " << i << " - tempo usuário: " << durationUserTimeS << "ms - tempo sistema: " << durationSysTimeS << "ms"<< endl;
        
        getrusage(RUSAGE_SELF, &r_usage);
        cout << "Memória usada: " << r_usage.ru_maxrss << endl << endl;

        File << durationUserTimeI << ";" << durationSysTimeI << ";" << durationUserTimeR << ";" << durationSysTimeR << ";" << r_usage.ru_maxrss << endl;
        
    }
    File.close();
    cout << "Terminou!!!";
}