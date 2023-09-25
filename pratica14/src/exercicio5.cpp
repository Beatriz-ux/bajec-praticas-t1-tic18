#include <iostream>

using namespace std;

struct aluno{
    string nome;
    string sobrenome;
    int idade;
    int numMatricula;
};

struct professor{
    string nome;
    string sobrenome;
    int numRegistro;
};

struct disciplina{
    string nome;
    int cargaHoraria;
    professor prof;
};

int main(void){

    return 0;
}
