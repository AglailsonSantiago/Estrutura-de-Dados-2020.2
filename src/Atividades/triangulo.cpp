#include <iostream>
#include <iomanip>
using namespace std;

void print(int *v, int n, int ini = 0){
    if(ini < n - 1){   
        cout << v[ini] << ", ";
        print(v, n, ini+1);
    }
    else{
        cout << v[n-1];
    }
}

void triangulo(int *v, int n){
    if(n > 0){
        int aux[n-1];
        for(int i = 0; i < n; i++){
            aux[i] = v[i] + v[i+1];
        }
        triangulo(aux, n-1);
        cout << "[";
        print(v, n);
        cout << "]" << "\n";
    }
}

int main(){
    int n;
    cin >> n;
    int v[n];

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    triangulo(v, n);
}