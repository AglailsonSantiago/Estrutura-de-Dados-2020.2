#ifndef LISTCIRC2_H
#define LISTCIRC2_H

struct Node;

class List {
public:
    // Construtor: cria uma lista simplesmente encadeada circular
    // com no cabeca. O no cabeca eh obrigatorio na implementacao desta lista
    List(); 

    // Destrutor: libera toda memoria que foi alocada
    ~List(); 

    // contains: retorna true se a lista contem um no com valor x;
    // retorna false caso contrario
    bool contains(int x); 

    // empty: retorna true se a lista estiver vazia;
    // retorna false caso contrario
    bool empty(); 

    // size: retorna a quantidade de elementos na lista
    int size(); 

    // clear: deixa a lista vazia, sem elementos  
    void clear(); 
    
    // add_back: insere um no com valor x ao final da lista
    void add_back(int x); 
    
    // add_front: insere um no com valor x no inicio da lista
    void add_front(int x); 
    
    // remove_front: remove o elemento que esta no inicio da lista
    // retorna o valor do no caso ele exista; 
    // ou retorna INT_MIN caso não exista primeiro elemento
    int remove_front();

    // remove_back: remove o elemento que esta no final da lista 
    // retorna o valor do no caso ele exista; 
    // ou retorna INT_MIN caso não exista ultimo elemento
    int remove_back();

    // remove: remove o primeiro no com valor x
    void remove(int x); 

    // removeAll: remove todos os nos com valor x
    void removeAll(int x); 
    
    // toString: retorna a lista como uma std::string
    std::string toString();
    
private:
    // Ponteiro para o no cabeca da lista
    Node *head;

    // Operacao auxiliar: retorna o no anterior ao no com valor x; 
    // ou retorna nullptr caso nenhum no com valor x esteja presente 
    Node *search(int x);
};

#endif