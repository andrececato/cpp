/* programa_006.cpp */

#include <stdlib.h> // necessário para malloc e free
#include <iostream>

using namespace std;

struct ST_DADOS {
    char Nome[40];
    float Salario;

    /* estrutura dentro de uma estrutura */
    struct Nascimento {
        int Ano;
        int Mes;
        int Dia;
    } DataNascimento;
};

int main(void) {

    /* ponteiro para a estrutura */
    struct ST_DADOS * p;

    /* alocao de memoria para o ponteiro da estrutura */
    cout << "Tamanho da estrutura:" << sizeof(struct ST_DADOS) << endl;
    p = (struct ST_DADOS *) malloc(sizeof(struct ST_DADOS));

    cout << "Entre com o nome ->";
    cin >> p->Nome;

    cout << "Entre com o salario ->";
    cin >> p->Salario;

    /* O -> eh chamado de pointer member (apontador de membro). Ele eh usado para
       referenciar um campo da estrutura no lugar do ponto (.) */
    cout << "Entre com o nascimento ->";
    cin >> p->DataNascimento.Dia;
    cin >> p->DataNascimento.Mes;
    cin >> p->DataNascimento.Ano;

    cout << endl << "===== Dados digitados ====" << endl;
    cout << "Nome = " << p->Nome << endl;
    cout << "Salario = " << p->Salario << endl;
    cout << "Nascimento = " << p->DataNascimento.Dia << "/"
         << p->DataNascimento.Mes << "/"
         << p->DataNascimento.Ano << endl;

    free(p);
    int i;
    cout << "Digite o tamanho:";
    cin >> i;
    p = (struct ST_DADOS *) malloc(sizeof(struct ST_DADOS)*i);

    for( int k =0; k<i; ++k) {
        cout << "Entre com o nome ->";
        cin >> p[k].Nome;

        cout << "Entre com o salario ->";
        cin >> p[k].Salario;
        cout << "Entre com o nascimento ->";
        cin >> p[k].DataNascimento.Dia;
        cin >> p[k].DataNascimento.Mes;
        cin >> p[k].DataNascimento.Ano;

    }

    for( int k =0; k<i; ++k) {
        cout << "Nome ["<<k<<"]: " << p[k].Nome << endl;
        cout << "Salario = " << p[k].Salario << endl;
        cout << "Nascimento = " << p[k].DataNascimento.Dia << "/"
             << p[k].DataNascimento.Mes << "/"
             << p[k].DataNascimento.Ano << endl;

    }
    free(p);
}
