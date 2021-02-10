#include <iostream>
#include <iomanip>

using namespace std;

struct Aluno{
    int matricula;
    char nome[100];
    double media;
} aluno;

int main(){

    int n, m;

    cin >> n;

    Aluno alunos[n];

    for(int i = 0; i < n; i++){

        cin >> alunos[i].matricula;

        cin.ignore();

        cin.get(alunos[i].nome, 100);

        cin.ignore();

        cin >> alunos[i].media;

    }

    cin >> m;

    int posicao = -1;

    for(int i = 0; i < n; i++){
        if(alunos[i].matricula == m){
            posicao = i;
            break;
        }
    }

    if(posicao != -1){
        cout << alunos[posicao].nome << "\n";
        cout << alunos[posicao].media;
    }
    else cout << "NAO ENCONTRADA";
    
}