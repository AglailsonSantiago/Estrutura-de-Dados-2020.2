#ifndef MATRIZ_H
#define MATRIZ_H
#include <string>
#include <vector> // biblioteca usada para criar um vetor de strings
#include <sstream>

using namespace std;

struct Node;

class Matriz {
private:
   // Ponteiro para o no cabeça da lista.
   Node *head; 

   // variaveis auxiliares para guarda a quantidade de linhas e a quantidade de colunas.
   int auxLinha;
   int auxColuna;

   // função auxiliar para realizar os split nos arquivos.
   vector<string> splitString(const string& str, char virgula);

   // função auxiliar para crias cabeças das linhas e colunas.
   void newHeads(int l, int c);

   // função auxiliar que irá ajudar na multiplicação.
   double auxMultiplicacao(Matriz *mat, int linha, int coluna);

public:
   // Construtor
   Matriz(); 
   

   // Destrutor: libera memoria alocada
   ~Matriz(); 


   // Esse método lê, de um arquivo de entrada, os elementos diferentes de zero de uma
   // matriz e monta a estrutura especificada anteriormente.
   void lerMatriz(std::string nome_do_arquivo);


   // Esse método imprime (uma linha da matriz por linha na saı́da) a matriz A, inclusive
   // os elementos iguais a zero.
   void imprime();


   // Esse método insere o valor v na linha i, coluna j da matriz A.
   void insere(int i, int j, double v);


   // Essa função recebe como parâmetro as matrizes A e B, devolvendo uma matriz C
   // que é a soma de A com B.
   Matriz *soma(Matriz *A, Matriz *B);


   // Esse método recebe como parâmetro as matrizes A e B, devolvendo uma matriz C
   // que é o produto de A por B.
   Matriz *multiplica(Matriz *A, Matriz *B);
   
};

#endif