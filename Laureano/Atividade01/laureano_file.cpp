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
        //p = (struct data_clients *) malloc(sizeof(struct data_clients)*1000);

        for( int k =0; k<quanti; ++k) {

            p[k].name = getRandomName(getRandomNumer(1,10));

            p[k].age = getRandomNumer(0,60);


            //cout << endl << i << " Cliente numero " << k << " criado com sucesso!!!" << endl << "Nome: " << p[k].name << endl << "Idade: " << p[k].age << endl;

            cont++;
        }
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
        //free(p);

    //cout << "Número aleatório: " << getRandomNumer(0,60) << endl;

    //cout << "Letra aleatória: " << static_cast<char>(getRandomLetter()) << endl;

    //cout << "Nome aleatório: " << getRandomName(getRandomNumer(100,500)) << endl;

    //for(int i = 0; i < 100; i++){
        //cout << "Lote de clientes: " << i << endl;
        //for(int j = 0; j < 10000; j++){

            //struct data_clients *client = new struct data_clients;

            //(*client).name = getRandomName(getRandomNumer(100,500));

            //(*client).age = getRandomNumer(0,60);

            //cout << "Cliente número " << j << " criado com sucesso!!!" << endl << "Nome: " << (*client).name << endl << "Idade: " << (*client).age << endl;
    //    }
}
