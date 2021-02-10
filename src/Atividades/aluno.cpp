#include <iostream>

using namespace std;

struct Aluno{
    char nome[80];
    int matricula;
    char disciplina[120];
    double nota;
} aluno;

Aluno ler(){
    Aluno aluno;

    cin >> aluno.nome;

    cin.ignore();

    cin >> aluno.matricula;

    cin.ignore();

    cin >> aluno.disciplina;

    cin.ignore();

    cin >> aluno.nota;

    return aluno;
}

void verifica(Aluno aluno){

    if(aluno.nota < 7){
        cout << aluno.nome << " reprovado(a) em " << aluno.disciplina;
    }
    else cout << aluno.nome << " aprovado(a) em " << aluno.disciplina;

}

int main(){

    Aluno aluno = ler();

    verifica(aluno);
    
}