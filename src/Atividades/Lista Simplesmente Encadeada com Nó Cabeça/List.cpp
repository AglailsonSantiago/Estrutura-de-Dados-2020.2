/**
 * Implemente as funções-membro da classe List neste arquivo.
 * Algumas funções já estão implementadas abaixo
 */

// Implementacao da classe List
#include <iostream>
#include <climits>
#include "List.h"

using namespace std;

// Definicao do struct Node
// Possui dois campos: value (valor inteiro) e 
// next (que eh um ponteiro para Node)
// Em C++, structs tambem podem ter construtores e destrutores. Aqui,
// Eu coloquei um destrutor que imprime uma mensagem na tela a fim 
// de rastrear se todos os nos alocados dinamicamente serao todos liberados.
struct Node {
    int value; 
    Node *next; 
    ~Node() { std::cout << "Node " << this->value << " removido" << std::endl; }
};

// Construtor. 
// Como nossa lista simplesmente encadeada possui no cabeca,
// Alcoamos dinamicamente um no cabeca aqui no construtor e 
// inicializamos os valores de seus campos. Nao mexa nesses valores, 
// pois caso contrario, o Moodle nao reconhecera as saidas corretamente.
List::List() {
    head = new Node;
    head->value = -77777777;
    head->next = nullptr;
}

// Destrutor. Limpamos a lista e depois liberamos o no cabeca.
// Antes de sair, imprime mensagem na saida, avisando que a 
// lista foi liberada.
List::~List() {
    clear();
    delete head;
    std::cout << "lista liberada" << std::endl;
}

// Adiciona inteiro x ao final da lista 
void List::add(int x){
    Node *novoNo = new Node();
    novoNo->value = x;
    if(empty()){
        head->next = novoNo;
    }
    else{
        Node* aux = head;
        while (aux->next != nullptr)
        {
            aux = aux->next;
        }
        aux->next = novoNo;
    }
}

// retorna true se a lista estiver vazia;
// retorna false caso contrario
bool List::empty(){
    return (head->next == nullptr);
}

// Retorna numero de elementos contidos na lista
int List::size(){ 
    if(empty() == true) return 0;

    Node *aux = head->next;
    int tamanho = 0;
    
    do{
        aux = aux->next;
        tamanho++;
    }while(aux!=nullptr);
    return tamanho;
} 

// deixa a lista vazia, ou seja, com size() == 0
void List::clear(){
    Node* aux = head->next;
    Node* t = aux;
    while (aux != nullptr)
    {
        aux = aux->next;
        delete t;
        t = aux;
    }
    head->next=nullptr;
} 

// remove da lista o primeiro no com valor x 
void List::remove(int x){
    if(empty() == false){
        Node* aux = head;
        while (aux->next != nullptr)
        {
            if((aux->next)->value == x){
                Node* t = (aux->next)->next;
                delete aux->next;
                aux->next = t;
                break;
            } 
            aux = aux->next;
        } 
    }
} 

// remove da lista todos os nos com valor x
void List::removeAll(int x){
    if(empty() == false){
        Node* aux = head;
        while (aux->next != nullptr)
        {
            remove(x);
            aux = aux->next;
        } 
    }
}

// remove da lista encadeada o i-esimo no e retorna seu valor.
// Note que deve-se ter 1 <= i <= size();
// Caso contrario retornar o menor inteiro possivel INT_MIN, 
// que esta definido na biblioteca <climits>
int List::removeNodeAt(int i){
    if(empty() == true){
        return INT_MIN;
    }
    else{
        int j = 0;
        Node* aux = head->next;
        Node* t = head;

        while (aux != nullptr)
        {
            if(j == i){
                aux = aux->next;
                delete t->next;
                t->next = aux;
                return aux->value;
            }
            aux = aux->next;
            j++;
            t = t->next;
        }
        
    }
    return INT_MIN;
}

// Insere um novo no com valor x apos o i-esimo no da lista.
// Deve-se ter 0 <= i <= size() para que a insercao seja realizada; 
// caso contrario, nao sera realizada.
bool List::insertAfter(int x, int i){
    if(i >= 0 && i <= size()){
        int j = 0;
        Node* aux = head->next;
        Node* t = head;

        while (aux != nullptr)
        {
            if(j == i){
                aux->next->value = x;
                
            }
            aux = aux->next;
            j++;
            t = t->next;
        }
        return true;
        
    }
    return false;
}

// Retorna um ponteiro para uma copia desta lista.
// Para a implementacao desta funcao, eh permitido o uso de outras funcoes.
// Note que voce deve retornar uma copia e nao um ponteiro para esta lista.
List* List::copy(){
    List* lst= new List;
    if(empty() == false){
        Node* aux = head->next;
        while(aux != nullptr){
            lst->add(aux->value);
            aux = aux->next;
        }
    }
    return lst;
}

// Copia os elementos do array v para esta lista. 
// O array tem n elementos. 
// Todos os elementos anteriores da lista sao apagados.
// Para a implementacao desta funcao, eh permitido o uso de outras funcoes.
void List::copyArray(int v[], int n){
    this->clear();
    for(int i = 0; i < n; i++){
        this->add(v[i]);
    }
}

// Determina se a lista lst, passada por parametro, 
// eh igual a lista que chama esta funcao. 
// Observacao: duas listas sao iguais se elas tem o
// mesmo tamanho e o valor do k-esimo elemento da primeira lista eh igual
// ao valor do k-esimo elemento da segunda lista.
// Para a implementacao desta funcao esta proibido usar qualquer
// outra funcao. 
// --->> Atencao: Implemente esta funcao sem invocar funcoes auxiliares. <<----
bool List::equal(List *lst){
    if(this->empty() == false && lst->empty() == false){
        Node* aux= head->next;
        Node* t = lst->head->next;

        while(aux!=nullptr && t!=nullptr){
            if(t->value != aux->value)
                return false;
            t = t->next;
            aux = aux->next;
        }

        if(aux ==nullptr && t==nullptr)
            return true;
        else 
            return false;

    }
    return false;
}

// Concatena a lista atual com a lista lst passada 
// por referencia. Apos essa operacao, lst sera uma lista vazia, 
// ou seja, o unico no de lst sera o no cabeca.
// Para a implementacao desta funcao esta proibido usar qualquer
// outra funcao. 
// --->> Atencao: Implemente esta funcao sem invocar funcoes auxiliares. <<----
void List::concat(List *lst){
        if(lst->empty() == true){
        cout << "lista vazia\n";
    }
    else{
        Node* aux = head;
        //percorrer a lista para deixar o ponteiro movel no final
        while(aux->next != nullptr){
            aux = aux->next;//mover o ponteiro
        }//ja estando no final posso conectar com o inicio da outra lista (sem ser a cabeça)
        aux->next = lst->head->next;
        lst->head->next = nullptr;
    }
}

Node* auxReverse(Node* no){
    if(no->next == nullptr){
        return no;
    }
    else{
        Node* a = no;
        no = auxReverse(no->next);
        Node* aux = no; 

        while(aux->next != nullptr){
            aux= aux->next;
        }

        aux->next = a;
        a->next =nullptr;
        return no;     
    }
}

// Esta funcao inverte a ordem dos nos (o primeiro no passa a ser o
// ultimo, o segundo no passa a ser o penultimo, etc.) 
// Essa operacao faz isso sem criar novos nos, apenas altera os ponteiros.
// --->> Atencao: nao eh permitido alocar nos auxiliares. <<----
void List::reverse(){
    if(empty() == false){
        head->next = auxReverse(head->next);
    }
}

// Imprime elementos da lista
void List::print(){
    if(!this->empty()){
        Node* aux = head->next;
        
        for(int i = 0; i < size(); i++){
            if(i != (size()-1)){
                cout<<aux->value << ",";
            }
            else{
                cout<<aux->value;
            }
            
            aux = aux->next;
        }
    }
}

// Retorna a lista como uma string
// Por exemplo, se a lista tiver elementos 4,5,6,7 entao
// a funcao deve retornar a string "[4,5,6,7]"
// Se a lista for vazia, deve retornar a lista "[]"
string List::toString(){
    string inicio = "[";
    string final = "]";
    
    Node* aux = head->next;

    if(aux != nullptr){
        while (aux != nullptr)
        {
            if(aux->next == nullptr){
                inicio += to_string(aux->value);
            }
            else{
                inicio += to_string(aux->value) +",";
            }
            aux = aux->next;
        }
        return inicio + final;
        
    }
    return "[]";
}