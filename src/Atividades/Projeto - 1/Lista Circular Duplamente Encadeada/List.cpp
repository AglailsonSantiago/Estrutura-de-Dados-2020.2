// FRANCISCO TIERRY BARROS OLIVEIRA - 428028
// JOSÉ AGLAILSON SANTIAGO MARTINS  - 416735
#include <iostream>
#include <string>
#include <climits>
#include "List.h"
using namespace std;

struct Node {
    int value;
    Node *next;
    Node *back;
    ~Node() { std::cout << "no com valor " << value << " liberado" << std::endl; }
};

List::List() {
    head = new Node;
    head->next = head; // mantem a circularidade
    head->back = head; // mantem a circularidade
    head->value = 77777777;
}

List::~List() {
    clear();
    delete head;
    std::cout << "lista liberada" << std::endl;
}

int List::size() {
    int cont = 0;
    Node *aux = head->next;
    while(aux != head) {
        cont++;
        aux = aux->next;
    }
    return cont;
}

bool List::empty() {
    if(head->next == head && head->back == head) return true;
    else return false;  
}

void List::clear() {
    Node *aux1 = head->next;
    Node *aux2 = aux1;
    while(aux1 != head) {
        aux1 = aux1->next;
        delete aux2;
        aux2 = aux1;
    }
    head->next = head;
    head->back = head;
}


void List:: push_back(int key) {
    Node *last = head->back;
    Node *novo = new Node;
    novo->value = key;
    
    last->next = novo;
    head->back = novo;

    novo->back = last;
    novo->next = head;
}

int List::pop_back() {
    Node *last = head->back;
    Node *penult = last->back; 
    if(!empty()) {
        int x = last->value;

        penult->next = head;
        head->back = penult;
        delete last;
        return x;
    }
    else return INT_MIN;
}

void List::insertAfter(int key, int k) {
    if(k >= 0 && k <= size()) {
        Node *aux = head->next;
        Node *proximo = aux; 

        Node *last = head->back;

        Node *novo = new Node;
        novo->value = key;
        for(int p = 1; p <= size(); p++) {
            if(p == k){
                if(k == size()) { // inserir na ultima posição
                    aux->next = novo;
                    novo->next = head;
                    novo->back = aux;
                    last = novo;
                    break;
                }
                proximo = aux->next;
                aux->next = novo;
                novo->next = proximo;
                aux = aux->next;
            }
            aux = aux->next;
        }
    }
}

void List::remove(int key) {
    if(!empty()){
        Node *aux = head;

        while(aux->next != head){
            if(aux->next->value == key) {
                Node *proximo = aux->next->next; 
                delete aux->next;
                aux->next = proximo;
                proximo->back = aux;
                break;
            }
            aux = aux->next;
        }
    }
}

void List::removeAll(int key) {
    Node *aux = head;

    while(aux->next != head) {
        if(aux->next->value == key) {
            Node *proximo = aux->next->next; 
            delete aux->next;
            aux->next = proximo;
            proximo->back = aux;
            aux = aux;
        } 
        else aux = aux->next;
    }
}

void List::concat(List *lst) {
    Node *aux = head;
    Node *aux2 = lst->head;

    while(aux->next != head) { //percorrer a lista ate o ultimo elemento
        aux = aux->next;
    }
    while(aux2->next != lst->head) { //percorrer a lista ate o ultimo elemento
        aux2 = aux2->next;
        //o ultimo elemento da lista principal aponta para o primeiro da list lst
        aux->next = aux2;
        aux2->back = aux;
        aux = aux->next;
    }
    
    //manter a circularidade da list principal
    head->back = aux; // cabeça aponta para o último
    aux->next = head; // último aponta para a cabeça
    
    //manter a circualridade da lst
    aux2 = lst->head;
    aux2->next = aux2;  
    aux2->back = aux2;  

}


List* List::copy() {
    List *novo = new List;
    Node *aux = head->next;
    if(!empty()){
        for(int i = 0; i < size(); i++) {
            novo->push_back(aux->value);
            aux = aux->next;
        }
    }
    return novo;
}

void List::copyArray(int n, int arr[]) {
    if(n != 0) {
        for(int i = 0; i < n; i++) {
            push_back(arr[i]);
        }
        return;
    }
}                                                                                       

bool List::equal(List *lst) {
    if(head->next != head && lst->head->next != head){
        Node *aux1 = head->next;
        Node *aux2 = lst->head->next;

        while(aux1 != head && aux2 != lst->head) {
            if(aux1->value != aux2->value){
                return false;
            }
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
        if(aux1 == head && aux2 == lst->head){
            return true;
        }else return false;
        
    }
    else return false;
}


void List::printReverse() {
    if(!empty()){
        cout << "[ ";
        Node* aux = head->back;
        
        for(int i = 0; i < size(); i++){
            if(i < size()-1){
                cout<<aux->value << ", ";
            }
            else{
                cout<<aux->value;
            }
            
            aux = aux->back;
        }
        cout << " ]\n";
    }
    else cout << "[ ]\n";
}

void List::print() {
    if(!empty()){
        cout << "[ ";
        Node* aux = head->next;
        
        for(int i = 0; i < size(); i++){
            if(i < size()-1){
                cout << aux->value << ", ";
            }
            else{
                cout << aux->value;
            }
            aux = aux->next;
        }
        cout << " ]" << endl;
    }
    else cout << "[ ]" << endl;
}

