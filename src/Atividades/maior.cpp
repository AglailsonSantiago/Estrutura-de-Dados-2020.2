#include <iostream>
#include <iomanip>

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

void maiorNota(Aluno aluno1, Aluno aluno2){
    if(aluno1.nota > aluno2.nota) cout << fixed << setprecision(1) << aluno1.nome << " , " << aluno1.nota;

    else if(aluno1.nota < aluno2.nota) cout << fixed << setprecision(1) << aluno2.nome << " , " << aluno2.nota;

    else cout << fixed << setprecision(1) << aluno1.nome << " e " << aluno2.nome << " , " << aluno1.nota;
}

int main(){

    Aluno aluno1 = ler();

    Aluno aluno2 = ler();

    maiorNota(aluno1, aluno2);
    
}