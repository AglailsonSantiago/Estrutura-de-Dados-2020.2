#ifndef LIST_H
#define LIST_H
#include <string>

struct Node;

class List {
private:
   // Ponteiro para o no cabeca da lista
   Node *head; 
      
   // Operacao auxiliar: retorna no antecessor do no 
   // com valor x, ou nullptr caso x nao esteja presente 
   Node *search(int x); 

public:
   // Construtor
   List(); 
   
   // Destrutor: libera memoria alocada
   // Apos liberar a memoria alocada, esta funcao deve 
   // escrever na saida a mensagem "lista liberada"
   ~List(); 

   // Adiciona inteiro x ao final da lista 
   void add(int x); 

   // remove da lista o primeiro no com valor x 
   void remove(int x);   

   // retorna true se a lista estiver vazia;
   // retorna false caso contrario
   bool empty();

   // Retorna numero de elementos contidos na lista
   int size(); 
   
   // deixa a lista vazia, ou seja, com size() == 0
   void clear(); 

   // Imprime elementos da lista
   void print();

   // Retorna a lista como uma string
   // Por exemplo, se a lista tiver elementos 4,5,6,7 entao
   // a funcao deve retornar a string "[4,5,6,7]"
   // Se a lista for vazia, deve retornar a lista "[]"
   std::string toString();

   // remove da lista todos os nos com valor x
   void removeAll(int x); 
      
   // remove da lista encadeada o i-esimo no e retorna seu valor.
   // Note que deve-se ter 1 <= i <= size();
   // Caso contrario retornar o menor inteiro possivel INT_MIN, 
   // que esta definido na biblioteca <climits>
   int removeNodeAt(int i);

   // Insere um novo no com valor x apos o i-esimo no da lista.
   // Deve-se ter 0 <= i <= size() para que a insercao seja realizada; 
   // caso contrario, nao sera realizada.
   bool insertAfter(int x, int i);

   // Retorna um ponteiro para uma copia desta lista.
   // Para a implementacao desta funcao, eh permitido o uso de outras funcoes.
   // Note que voce deve retornar uma copia e nao um ponteiro para esta lista.
   List *copy();

   // Copia os elementos do array v para esta lista. 
   // O array tem n elementos. 
   // Todos os elementos anteriores da lista sao apagados.
   // Para a implementacao desta funcao, eh permitido o uso de outras funcoes.
   void copyArray(int v[], int n);

   // Determina se a lista lst, passada por parametro, 
   // eh igual a lista que chama esta funcao. 
   // Observacao: duas listas sao iguais se elas tem o
   // mesmo tamanho e o valor do k-esimo elemento da primeira lista eh igual
   // ao valor do k-esimo elemento da segunda lista.
   // Para a implementacao desta funcao esta proibido usar qualquer
   // outra funcao. 
   // --->> Atencao: Implemente esta funcao sem invocar funcoes auxiliares. <<----
   bool equal(List *lst);

   // Concatena a lista atual com a lista lst passada 
   // por referencia. Apos essa operacao, lst sera uma lista vazia, 
   // ou seja, o unico no de lst sera o no cabeca.
   // Para a implementacao desta funcao esta proibido usar qualquer
   // outra funcao. 
   // --->> Atencao: Implemente esta funcao sem invocar funcoes auxiliares. <<----
   void concat(List *lst); 

   // Esta funcao inverte a ordem dos nos (o primeiro no passa a ser o
   // ultimo, o segundo no passa a ser o penultimo, etc.) 
   // Essa operacao faz isso sem criar novos nos, apenas altera os ponteiros.
   // --->> Atencao: nao eh permitido alocar nos auxiliares. <<----
   void reverse();
};

#endif