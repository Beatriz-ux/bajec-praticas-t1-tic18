#include <iostream>

const int TAM_TURMA = 30;

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
    int codDisc;
    string nome;
    int cargaHoraria;
};

// dev: Caua
struct instituicao{
    string data_fundacao;
    string localizacao;
    int codigo_mec;
};

// dev: everaldina
struct turma{
    int ano;
    bool ativa;
    bool semestre; // 0 = 1º semestre, 1 = 2º semestre
    int numAlunos;
    int codProfessor;
    int codDisciplina;
    aluno alunos[TAM_TURMA];
};

int main(void){

    return 0;
}
