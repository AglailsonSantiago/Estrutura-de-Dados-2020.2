#include <iostream>
using namespace std;

bool primo(int n);

int main(){
    int a;
    cin >> a;

    int b;
    cin >> b;

    for(a; a <= b; a++){
        if(primo(a) == 1) cout << a << "\n";
    }

}

bool primo(int n){
    int cont = 0;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            cont++;
            break;
        }
    }
    if(cont == 0) return 1;
    else return 0;
}