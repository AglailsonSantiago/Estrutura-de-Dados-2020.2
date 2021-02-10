#include <iostream>
using namespace std;

int main(){
    int mat[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
        }
    }

    int aux= 0;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(mat[i][j] > mat[i+1][j]){
                aux++;
            }
        }
    }

    cout << aux;

}