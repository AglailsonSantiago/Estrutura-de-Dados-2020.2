#include <iostream>

using namespace std;

int main(){

    int n;

    cin >> n;

    float valor[n];

    float jog1[n];

    char jog2[n];

    int j1 = 0, j2 = 0; 

    for(int i = 0; i < n; i++){
        cin >> valor[i];
    }

    for(int i = 0; i < n; i++){
        cin >> jog1[i];
    }

    cin.ignore();
    
    for(int i = 0; i < n; i++){
        cin >> jog2[i];
    }

    for(int i = 0; i < n; i ++){
        if(((valor[i] > jog1[i]) && jog2[i] == 'M') || ((valor[i] < jog1[i]) && jog2[i] == 'm')){
            j2++;
        }
        else j1++;

    }

    if(j1 > j2) cout << "primeiro";
    
    else if(j2 > j1) cout << "segundo";
    
    else cout << "empate";
    
}