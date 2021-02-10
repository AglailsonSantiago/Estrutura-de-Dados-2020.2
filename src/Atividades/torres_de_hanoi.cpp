#include <iostream>

using namespace std;

void hanoi(int n, char origem, char destino, char aux){
    if(n == 1) cout << origem << " -> " << destino << "\n";
    else{
        hanoi(n-1, origem, aux, destino);
        hanoi(1, origem, destino, aux);
        hanoi(n-1, aux, destino, origem);

    }
}

int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
}