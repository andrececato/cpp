#include <iostream>
#include <random>

#include <fstream>

#include <unistd.h>

#include <sys/resource.h>

#include <unistd.h>

#include <random>

using namespace std;

const char ALPH[27] = "abcdefghijklmnopqrstuvwxyz";

int getRandomNumer(int min, int max){
    int random = min+(rand()% max);
    return random;
}

char getRandomLetter(){
    int r_numb = getRandomNumer(0,25);
    return ALPH[r_numb];
}

string getRandomName(int characters){
    string l_name = "";
    for(int i=0;i<characters;i++){
        l_name += getRandomLetter();
    }
    return l_name;

}


int main()
{
    struct data_clients
    {
        string name;
        int age;
    };

    struct rusage r_usage;



    ofstream Table("table.csv");

    Table << "user;system" << endl;



    int cont = 0;

    int quanti = 10000;

    struct data_clients * p;

    int quanti_while = 0;

    float temp_user = 0;

    float temp_sys = 0;

    while(quanti <= 1000000){

        p = new struct data_clients[quanti];

        for( int k =0; k<quanti; ++k) {

            p[k].name = getRandomName(getRandomNumer(100,500));

            p[k].age = getRandomNumer(1,60);

            cont++;

        }
        getrusage(RUSAGE_SELF, &r_usage);

        float userTime = r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0;

        float sysTime = r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0;

        Table << userTime << ";" << sysTime << endl;

        cout << quanti_while << " lote - " << cont << " clientes cadastrados - " << "Tempo de execucao (usuario): " << userTime << " - Tempo de execucao (sistema): " << sysTime << endl;

        delete [] p;

        quanti+=10000;

        quanti_while++;

        temp_user+=0.562312312412;

        temp_sys+=0.123123114153;



    }

    float userTime = r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0;

    float sysTime = r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0;

    cout << "Clientes adicionados: " << cont << endl;

    cout << "Quantidade de while: " <<quanti_while << endl;

    cout << "Tempo usuario: " << userTime << endl;

    cout << "Tempo sistema: " << sysTime << endl;
}

