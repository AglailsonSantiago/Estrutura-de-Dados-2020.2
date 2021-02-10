// Implementacao do TAD Matriz
#include <iostream>
#include <iomanip> 
#include "Matriz.h"
using namespace std;

Matriz :: Matriz(int l, int c){
    this->_l = l;
    this->_c = c;
    _M = new float*[_l];
    for(int i = 0; i < _l; i++){
        float *v = new float[c];
        _M[i] = v;
    }
}

Matriz :: ~Matriz(){
    delete[] _M;
    cout << "matriz liberada" << endl;
}

int Matriz :: linhas(){
    return _l;
}

int Matriz :: colunas(){
    return _c;
}

void Matriz :: imprime(int largura){
    for(int i = 0; i < _l; i++){
        for(int j = 0; j < _c; j++){
            cout << setw(largura) << _M[i][j] << "\t";
        }
        cout << "\n";
    }

}

float Matriz :: valor(int i, int j){
    return _M[i][j];
} 

void Matriz :: atribui(float v, int i, int j){
    _M[i][j] = v;
}

Matriz* Matriz :: soma(Matriz *B){
    Matriz *C;
    if(B->_l == _l && B->_c == _c){
        C = new (nothrow) Matriz(B->_l, B->_c);
        for(int i = 0; i < _l; i++){
            for(int j = 0; j < _c; j++){
                C->_M[i][j]= B->_M[i][j] + _M[i][j];
            }
        }
        return C;
    }
    else return nullptr;
}

Matriz* Matriz :: multiplica(Matriz *B){
    if(B->_l == _c){
        Matriz *C = new Matriz(_l, B->_c);
        float aux = 0;
        for(int i = 0; i < _l; i++){
            for(int j = 0; j < B->_c; j++){
                C->_M[i][j]= 0;
                for(int x = 0; x < B->_l; x++){
                    aux = aux + (_M[i][x] * B->_M[x][j]);
                }
                C->_M[i][j] = aux;
                aux = 0;
            }
        }
        return C;
    }
    else return nullptr;
}