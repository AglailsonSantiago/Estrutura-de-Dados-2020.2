#include <iostream>
using namespace std;

int main(){
    int mat[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
        }
    }

    int maior = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(mat[i][j] > maior){
                maior = mat[i][j];
            }
        }
    }

    int somaL = 0, somaC = 0, somaD = 0;

    for(int i = 0; i < 3; i++){
        somaL += mat[0][i];
    }

    for(int i = 0; i < 3; i++){
        somaC += mat[i][0];
    }

    for(int i = 0; i < 3; i++){
        somaD += mat[i][i];
    }

    if((somaL == somaC && somaL == somaD) && maior == 9){
        cout << "sim";
    }
    else cout << "nao";

}