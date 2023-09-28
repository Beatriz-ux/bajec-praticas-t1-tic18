#include <iostream>
#include <vector>



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

// dev: Caua
struct diretor{
    string nome;
    string sobrenome;
    string grau_academico;
    int tempo_de_atuacao;
};

struct Escola{
    string nome;
    string endereco;
    int numTurmas;
    int numProfessores;
    int numDisciplinas;
    vector <turma> turmas;

    vector <professor> professores;
    vector <disciplina> disciplinas;
    diretor Diretor;
};

void estruturaEscola(Escola escola);
int main(void){
    Escola escola;
    escola.nome = "SABER";
    escola.endereco = "Rua X, n 0";
    escola.numTurmas = 0;
    escola.numProfessores = 0;
    escola.numDisciplinas = 0;

    professor prof1;
    prof1.nome = "Joao";
    prof1.sobrenome = "Silva";
    prof1.numRegistro = 1;
    escola.professores.push_back(prof1);

    professor prof2;
    prof2.nome = "Maria";
    prof2.sobrenome = "Santos";
    prof2.numRegistro = 2;
    escola.professores.push_back(prof2);

    disciplina disc1;
    disc1.codDisc = 1;
    disc1.nome = "Matematica";
    disc1.cargaHoraria = 60;
    escola.disciplinas.push_back(disc1);

    disciplina disc2;
    disc2.codDisc = 2;
    disc2.nome = "Portugues";
    disc2.cargaHoraria = 50;
    escola.disciplinas.push_back(disc2);

    disciplina disc3;
    disc3.codDisc = 3;
    disc3.nome = "Ingles";
    disc3.cargaHoraria = 40;
    escola.disciplinas.push_back(disc3);

    aluno aluno1;
    aluno1.nome = "Lucas";
    aluno1.sobrenome = "Silva";
    aluno1.idade = 15;
    aluno1.numMatricula = 1;

    aluno aluno2;
    aluno2.nome = "Ana";
    aluno2.sobrenome = "Santos";
    aluno2.idade = 16;

    turma turma1;
    turma1.ano = 2023;
    turma1.ativa = true;
    turma1.semestre = 1;
    turma1.numAlunos = 0;
    turma1.codDisciplina = 1;
    turma1.codProfessor = 1;

    turma turma2;
    turma2.ano = 2023;
    turma2.ativa = true;
    turma2.semestre = 1;
    turma2.numAlunos = 0;
    turma2.codDisciplina = 2;
    turma2.codProfessor = 2;



    turma1.alunos[0] = aluno1;
    turma1.alunos[1] = aluno2;
    turma1.numAlunos = 2;

    turma2.alunos[0] = aluno1;
    turma2.alunos[1] = aluno2;
    turma2.numAlunos = 2;

    escola.turmas.push_back(turma1);
    escola.turmas.push_back(turma2);
    escola.numTurmas = escola.turmas.size();
    escola.numProfessores = escola.professores.size();
    escola.numDisciplinas = escola.disciplinas.size();
    
    diretor Diretor;
    Diretor.nome = "Jose";
    Diretor.sobrenome = "Oliveira";
    Diretor.tempo_de_atuacao = 10;
    Diretor.grau_academico = "Doutor";
    escola.Diretor = Diretor;

    estruturaEscola(escola);





    return 0;
}
void estruturaEscola(Escola escola){
    cout << "Nome da escola: " << escola.nome << endl;
    cout << "Nome do Diretor: " << escola.Diretor.nome << " " << escola.Diretor.sobrenome << endl;
    cout << "Endereco da escola: " << escola.endereco << endl;
    cout << "Numero de turmas: " << escola.numTurmas << endl;
    cout << "Numero de professores: " << escola.numProfessores << endl;
    cout << "Numero de disciplinas: " << escola.numDisciplinas << endl;
    cout << "Turmas: " << endl;
    for(int i = 0; i < escola.numTurmas; i++){
        cout << "\tTurma " << i + 1 << endl;
        cout << "\tAno: " << escola.turmas[i].ano << endl;
        cout << "\tAtiva: " << (escola.turmas[i].ativa ? "Sim" : "Nao") << endl;
        cout << "\tSemestre: " << escola.turmas[i].semestre << endl;
        cout << "\tNumero de alunos: " << escola.turmas[i].numAlunos << endl;
        cout << "\tProfessor da turma: ";
        for(int j = 0; j < escola.numProfessores; j++){
            if(escola.turmas[i].codProfessor == escola.professores[j].numRegistro){
                cout << escola.professores[j].nome << " " << escola.professores[j].sobrenome << endl;
            }
        }
        cout << "\tDisciplina: " ;
        for(int j = 0; j < escola.numDisciplinas; j++){
            if(escola.turmas[i].codDisciplina == escola.disciplinas[j].codDisc){
                cout << escola.disciplinas[j].nome << endl;
            }
        }
        cout << "\tAlunos: " << endl;
        for(int j = 0; j < escola.turmas[i].numAlunos; j++){
            cout << "\t\tNome: " << escola.turmas[i].alunos[j].nome << " "<< escola.turmas[i].alunos[j].sobrenome << endl;
            cout << "\t\tIdade: " << escola.turmas[i].alunos[j].idade << endl;
            cout << "\t\tNumero de matricula: " << escola.turmas[i].alunos[j].numMatricula << endl;
            cout << endl;
        }
    }
}
