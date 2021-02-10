#include <iostream>
using namespace std;

int main(){

    int n;

    cin >> n;

    int vet[n];

    int verifica = 1;

    for(int i = 0; i < n; i++){
            cin >> vet[i];
    }

    for(int i = 0; i < (n-1); i++){
        if(vet[i] > vet[i+1]) {
            verifica = 0;
            break;
        }
    }  
    
    if (verifica == 1) cout << "ok";
    else cout << "precisa de ajuste"; 

}