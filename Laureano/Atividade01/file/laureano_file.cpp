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

    struct rusage r_usage; //estrutura de medicao de memória
    getrusage(RUSAGE_SELF,&r_usage); //mede a memória do próprio processo

    std::cout << "Uso de memória antes ..." << std::endl;
    std::cout << "MT:" << r_usage.ru_maxrss << "KB " << std::endl;
    std::cout << r_usage.ru_utime.tv_sec << ":" << r_usage.ru_stime.tv_sec << std::endl;

    ofstream Table("table.csv");
    Table << "user;system";

    int cont = 0;
    int quanti = 10000;
    struct data_clients * p;
    int quanti_while = 0;
    while(quanti <= 1000000){
        cout << quanti_while << " lote - " << cont << " clientes cadastrados - " << endl;
        p = new struct data_clients[quanti];
        //p = (struct data_clients *) malloc(sizeof(struct data_clients)*1000);

        for( int k =0; k<quanti; ++k) {

            p[k].name = getRandomName(getRandomNumer(1,10));

            p[k].age = getRandomNumer(0,60);

            //cout << endl << i << " Cliente numero " << k << " criado com sucesso!!!" << endl << "Nome: " << p[k].name << endl << "Idade: " << p[k].age << endl;

            cont++;
        }
        delete [] p;
        quanti+=10000;
        quanti_while++;
    }
    cout << "Clientes adicionados: " << cont << endl;
    cout << "Quantidade de while: " <<quanti_while << endl;
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
