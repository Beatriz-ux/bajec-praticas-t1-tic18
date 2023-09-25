#include <iostream>

using namespace std;

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