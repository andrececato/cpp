#include <iostream>
#include <sys/resource.h>
#include <unistd.h>
#include <random>

using namespace std;

int getRandomNumer(){
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(25, 63); // define the range

    for(int n=0; n<40; ++n)
        cout << distr(gen) << ' '; // generate numbers

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

    // código que você quer medir começando aqui
    for( int i=1; i<100; ++i)
    {
        char *p = new char[i*1048576];
        std::cout << "Endereço:" << (int*)p  << std::endl;
        for(int k=0; k<(i*1048576)-1; ++k)
        {
            p[k]=' ';
        }

        //terminando aqui o código que você quer medir
        // pegando as informações novamente
        getrusage(RUSAGE_SELF, &r_usage);

        //memória utilizada agora
        std::cout << "MT:" << i << ":"<< r_usage.ru_maxrss << "KB " << std::endl;
        // calcula tempo de CPU no modo de usuário e sistema
        double userTime = r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0;
        double sysTime = r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0;

        std::cout << "Tempo de CPU para usuário: " << userTime << " seconds" << std::endl;
        std::cout << "Tempo de CPU para sistema: " << sysTime << " seconds" << std::endl;
        std::cout << r_usage.ru_utime.tv_sec << ":" << r_usage.ru_stime.tv_sec << ":"
                  << r_usage.ru_utime.tv_usec << ":"<< r_usage.ru_stime.tv_usec << std::endl;

        delete [] p; //libera memória para uma nova alocação

        p = nullptr;
    }

    //terminando aqui o código que você quer medir
    // pegando as informações novamente
    getrusage(RUSAGE_SELF, &r_usage);

    //memória utilizada agora
    std::cout << " finalizei MT:" << r_usage.ru_maxrss << "KB " << std::endl;
    // calcula tempo de CPU no modo de usuário e sistema
    double userTime = r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0;
    double sysTime = r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0;


    std::cout << "Tempo de CPU para usuário: " << userTime << " seconds" << std::endl;
    std::cout << "Tempo de CPU para sistema: " << sysTime << " seconds" << std::endl;

    std::cout << "Dormindo 5 segundos....." << std::endl ;
    sleep(5);


    // pegando as informações novamente
    getrusage(RUSAGE_SELF, &r_usage);
    //memória utilizada agora
    std::cout << " finalizei again MT:" << r_usage.ru_maxrss << "KB " << std::endl;
    // calcula tempo de CPU no modo de usuário e sistema
    userTime = r_usage.ru_utime.tv_sec + r_usage.ru_utime.tv_usec / 1000000.0;
    sysTime = r_usage.ru_stime.tv_sec + r_usage.ru_stime.tv_usec / 1000000.0;

    std::cout << "Tempo de CPU para usuário: " << userTime << " seconds" << std::endl;
    std::cout << "Tempo de CPU para sistema: " << sysTime << " seconds" << std::endl;

    /*
    Tempo de Usuário (User Time): Refere-se ao tempo em que a CPU foi dedicada à execução do código do usuário.
    Isso inclui o tempo gasto executando instruções no espaço de usuário, como as partes do programa que você escreveu.
    O tempo de usuário não inclui o tempo gasto no sistema operacional para operações de gerenciamento de recursos,
    como leitura/gravação de arquivos ou alocação de memória.

    Tempo de Sistema (System Time): Refere-se ao tempo em que a CPU foi dedicada à execução de código do
    sistema operacional em nome do seu programa. Isso inclui o tempo gasto no kernel do sistema operacional para realizar tarefas
    como alocação de recursos, gerenciamento de dispositivos, etc.
    O tempo de sistema não está diretamente associado à execução do código que você escreveu, mas sim ao tempo gasto em
    operações de sistema em nome do seu programa.
    */

    return 0;
}
