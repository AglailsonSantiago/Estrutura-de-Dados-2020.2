// Implementacao da classe SeqList
#include <iostream>
#include <string> 
#include <sstream>

#include "SeqList.h"
using namespace std;

SeqList :: SeqList(int n){
    this->size_vec = 0;
    this->capacity_vec = n;
    this->vec = new (nothrow) int[n];

    if(vec == nullptr){
        cerr << "error" << endl;
        exit(1);
    }

}

SeqList :: ~SeqList(){
    if(vec != nullptr){ 
        delete[] vec;
        cout << "lista removida" << endl;
    }
}

bool SeqList :: add(int x){
    if(isFull() == false){
        vec[size_vec] = x;
        size_vec++;
        return true;
    }
    else{
        return false;
    }
} 

bool SeqList :: remove(int x){
    int k = search(x);
    if(k == -1) return false;
    else{
        for(int i = k; i <= size_vec; i++){
            if(k == size_vec){
                size_vec--;
            }
            else {
                vec[i] = vec[i+1];
            }
        }
        size_vec--;
        return true;
    }
}

bool SeqList :: isFull(){
    if(size_vec == capacity_vec) return true;
    else return false;
}

int SeqList :: size() {
    return size_vec;
}

int SeqList :: search(int x){
    for(int i = 0; i < size_vec; i++){
        if(vec[i] == x) return i;
    }
    return -1;
}

int SeqList :: at(int k){
    if(k >= 0 && k < size_vec){
        return vec[k];
    }
    else{
        return 0;
    }
}

void SeqList :: clear(){
    size_vec = 0;
}

bool SeqList :: replaceAt(int x, int k){
    if(k >= 0 && k < size_vec){
        vec[k] = x;
        return true;
    }
    return false;
}

bool SeqList :: removeAt(int k){
    if(k >= 0 && k < size_vec){
        for(int i = k; i < size_vec; i++){
            if(k != size_vec-1){
                vec[i] = vec[i+1];
            }
        }
        size_vec--;
        return true;
    }
    return false;
}

bool SeqList :: insertAt(int x, int k){
    if(k >= 0 && k <= size_vec && size_vec < capacity_vec){
        for(int i = k; i < size_vec; i++){
            vec[i+1] = vec[i];
        }
        size_vec++;
        vec[k] = x;
        return true;
    }
    return false;
}

void SeqList :: removeAll(int x){
    int aux = 0;
    int pos = 0;

    for(int i = 0; i < size_vec; i++){
        if(vec[i] == x) {
            aux++;
            pos = i;
        }
    }

    if(aux > 0){
        for(int i = pos; i <= size_vec; i++){
            if(i == size_vec){
                size_vec--;
            }
            else {
                vec[i] = vec[i+1];
            }
        }
        aux = 0;
        pos = 0;
        removeAll(x); 
    }
    
}

string SeqList :: toString() {
    string s = "[";
    for(int i = 0; i < size_vec; i++){
        if(i == size_vec-1){
            s += to_string(vec[i]) + "]";    
        }
        else s += to_string(vec[i]) + ",";
    }
    return s;
}