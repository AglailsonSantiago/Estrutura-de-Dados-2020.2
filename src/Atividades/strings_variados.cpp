#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char **nomes = new (nothrow) char*[n];
    int tamanho;
    char *nome;

    for(int i = 0; i < n; i++){
        cin >> tamanho;
        nome = new (nothrow) char[tamanho+1];
        cin.ignore();
        cin.get(nome, tamanho+1);
        nomes[i] = nome;
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            char *aux;
            if(strcmp(nomes[j], nomes[j+1]) > 0){
                aux = nomes[j];
                nomes[j] = nomes[j+1];
                nomes[j+1] = aux;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << nomes[i] << "\n";
    }

    delete[] nomes;
    delete[] nome;
}