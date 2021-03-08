#include <iostream>
#include <string>
#include <climits>
#include "List.h"

using namespace std;

struct Node {
    int value;
    Node *next;
    ~Node() { std::cout << "no com valor " << value << " liberado" << std::endl; }
};

List::List() {
    head = new Node;
    head->next = head;
    head->value = -77777777;
}

// Completar
List::~List() {
    if(!empty()){
        Node *aux = head->next;
        Node *t = aux;
        while(aux != head){
            aux = aux->next;
            delete t;
            t = aux;
        }
    }
    delete head;
    cout << "lista liberada" << endl;
}

// clear: deixa a lista vazia, sem elementos  
void List::clear(){
    if(!empty()){
        Node *aux = head->next;
        Node *t = aux;
        while(aux != head){
            aux = aux->next;
            delete t;
            t = aux;
        }
        head->next = head;
    }
}

// contains: retorna true se a lista contem um no com valor x;
// retorna false caso contrario
bool List::contains(int x){
    if(!empty()){
        Node *aux = head->next;
        while(aux != head){
            if(aux->value == x){
                return true;
            }
            aux = aux->next;
        }
    }
        return false;
}

// empty: retorna true se a lista estiver vazia;
// retorna false caso contrario
bool List::empty(){
    return (head->next == head);
}

// size: retorna a quantidade de elementos na lista
int List::size(){
    if(!empty()){
        int cont = 0;
        Node *aux = head->next;
        while(aux != head){
            cont++;
            aux = aux->next;
        }
        return cont;
    }
    return 0;
}

// add_back: insere um no com valor x ao final da lista
void List::add_back(int x){
    Node *novoNo = new Node();
    novoNo->value = x;
    novoNo->next = head;
    if(empty()){
        head->next = novoNo;
    }
    else{
        Node *aux = head;
        while (aux->next != head)
        {
            aux = aux->next;
        }
        aux->next = novoNo;
    }
}

// add_front: insere um no com valor x no inicio da lista
void List::add_front(int x){
    Node *aux = head->next;
    Node *novoNo = new Node();
    novoNo->value = x;
    head->next = novoNo;
    novoNo->next = aux;
}

// remove_back: remove o elemento que esta no final da lista 
// retorna o valor do no caso ele exista; 
// ou retorna INT_MIN caso não exista ultimo elemento
int List::remove_back(){
    if(!empty()){
        Node *aux = head;
        Node *t = aux;

        while(aux->next != head){
            t = aux;
            aux = aux->next;
        }
        int res = aux->value;
        delete aux;
        t->next = head;
        return res;
    }
    else return INT_MIN;
}

// remove_front: remove o elemento que esta no inicio da lista
// retorna o valor do no caso ele exista; 
// ou retorna INT_MIN caso não exista primeiro elemento
int List::remove_front(){
    if(!empty()){
        Node *aux = head->next;
        Node *t = aux;
        
        t = aux->next;
        
        int res = aux->value;
        delete aux;

        head->next = t;

        return res;
    }
    else return INT_MIN;
}

// remove: remove o primeiro no com valor x
void List::remove(int x){
    if(empty() == false){
        Node *aux = head;
        while (aux->next != head)
        {
            if(aux->next->value == x){
                Node* t = aux->next->next;
                delete aux->next;
                aux->next = t;
                break;
            } 
            aux = aux->next;
        } 
    }
} 

// removeAll: remove todos os nos com valor x
void List::removeAll(int x){
    if(empty() == false){
        Node *aux = head;
        while (aux->next != head)
        {
            if(aux->next->value == x){
                Node *t = aux->next->next;
                delete aux->next;
                aux->next = t;
                aux = aux;
            }
            else aux = aux->next;
        } 
    }
} 

// toString: retorna a lista como uma std::string
std::string List::toString(){
    string inicio = "[";
    string final = "]";
    
    Node* aux = head->next;

    if(!empty()){
        while (aux != head)
        {
            if(aux->next == head){
                inicio += to_string(aux->value);
            }
            else{
                inicio += to_string(aux->value) +",";
            }
            aux = aux->next;
        }
        return inicio + final;
        
    }
    else return "[]";
}