// FRANCISCO TIERRY BARROS OLIVEIRA - 428028
// JOSÉ AGLAILSON SANTIAGO MARTINS  - 416735
#include <iostream>
#include <string>
#include <climits>
#include <iomanip> 
#include <fstream> // biblioteca para ler arquivo
#include <sstream> // biblioteca para auxiliar a manipulação de strings
#include "Matriz.h"
using namespace std;

struct Node {
    Node *direita;
    Node *abaixo;
    int linha;
    int coluna;
    double valor;
};

Matriz::Matriz() {
    head = new Node;

    head->direita = head;  // mantem a circularidade a direita.
    head->abaixo = head;  // mantem a circularidade abaixo.

    head->linha = -1;  // inicia a linha e coluna da cabeça principal como -1.
    head->coluna = -1;
}

Matriz::~Matriz() {
    Node *aux1 = head->direita;
    Node *aux2 = head->abaixo;

    Node *prox1 = aux1;  // ponteiro para as duas listas, que vai auxiliar a percorrê-las.
    Node *prox2 = aux2;

    while(aux1 != head && aux2 != head) {
        aux1 = aux1->direita;  // percorre as listas deletando cada uma
        aux2 = aux2->abaixo;  // ate chegar a cabeça de cada uma delas.
        delete prox1;
        delete prox2;

        prox1 = aux1;  // referencia os Node novamente para continuar o
        prox2 = aux2; // o fluxo de percorrer e deletar.
    }
    head->direita = head;  // para continuar mantendo a circularidade.
    head->abaixo = head;

    delete head;
    cout << "matriz liberada" << endl;
}

vector<string> Matriz::splitString(const string& str, char virgula) {
  vector<string> result;  // vetor de strings que ira armazenar o resultado do split
  string aux;
  stringstream value(str);  // string a ser analisada.
  if (str == "") {  // se a string analisada for vazia retorna apenas o vetor vazio.
      return result;
  } 
  
  while (getline(value, aux, virgula)) {  // percorre a linha ate de encontrar a virgula
    result.push_back(aux);                // ao encontrar, se faz um split e guarda
  }                                       // o valor antes da virgula no vetor result.
  return result;                       
}


void Matriz::newHeads(int l, int c) {
    Node *aux = head; 
    int i = 1;  // consideramos que vamos ter elementos de 1 ate N, sendo N a
    int j = 1;  // quantidade de linhas ou colunas, logo iniciamos a variavel com 1.

    // cria as cabeças nas linhas.
    while(i <= l) {  // como l é a quantidade de linhas da matriz, percorremos ate chegar nela.
        Node *novo1 = new Node;
        novo1->linha = -1;  // todas as linhas de todas as cabeças na linha vão iniciar com -1.
        novo1->coluna = i;  // todas as colunas de todas as cabeças na linha vão iniciar com valor de 1 ate N.
        aux->abaixo = novo1;
        novo1->direita = novo1; 
        aux = novo1;
        i++;
    }
    aux->abaixo = head;  // mantem a circularidade
    aux = head;

    // cria as cabeças nas colunas.
    while(j <= c) {  // como c é a quantidade de colunas da matriz, percorremos ate chegar nela.
        Node *novo2 = new Node;
        novo2->coluna = -1;  // todas as colunas de todas as cabeças na coluna vão iniciar com -1.
        novo2->linha = j;  // todas as linhas de todas as cabeças na coluna vão iniciar com valor de 1 ate N.
        aux->direita = novo2;
        novo2->abaixo = novo2;
        aux = novo2;
        j++;
    }
    aux->direita = head;  // mantem a circularidade
}


void Matriz::lerMatriz(string nome_do_arquivo){
    ifstream arq;  
    arq.open(nome_do_arquivo);  // abre o arquivo a ser lido
    if(arq.is_open()) {
        int l = 0, c = 0;
        string values;  // values equivale a primeira linha do arq, onde contem a quantidade de linhas e colunas.
        getline(arq, values); // pega a primeira linha do arq, que é o tamanho da matriz
        
        // realiza o split nessa primeira linha e guarda seus valores em result
        vector<string> result = splitString(values, ','); 

        // converte a string que esta no vetor em stringstream, 
        // depois extrai o valor da stringstream e atribui ele a um inteiro.
        stringstream value1(result[0]); 
        stringstream value2(result[1]); 
        value1 >> l;
        value2 >> c;
        auxLinha = l;  // guarda o valor da linha e da coluna.
        auxColuna = c; 

        newHeads(l, c);  // passamos para a função os valores necessarios para se criar as cabeças.


        // ler as linhas restantes do arquivo ate o final, pois já lemos a primeira.
        while(!arq.eof()) {
            string text = " ";
            getline(arq, text);  // pega linha a linha do arquivo.

            int i=0, j=0;
            float v = 0;

            // realiza o split em cada linha.
            vector<string> resultado = splitString(text, ','); 

            // percorremos o vetor extraindo seus valores e guardando nas variaveis.
            for(int x=0; x < resultado.size(); x++) {
                stringstream pos_i(resultado[x-2]); 
                stringstream pos_j(resultado[x-1]);
                stringstream val_v(resultado[x]); 
                pos_i >> i;
                pos_j >> j;
                val_v >> v;
            }
            insere(i,j,v);  // insere cada valor lido na posição correta.
        }
        arq.close();  // por fim fecha o arquivo que foi aberto.
    }
    
}

void Matriz::insere(int i, int j, double v) {
    Node *row = head->abaixo;
    Node *column = head->direita;
    Node *novo = new (nothrow) Node;
    novo->linha = i;
    novo->coluna = j;
    novo->valor = v;
    

    // LINHAS
    int cont;
    for (cont = 1; cont < i; cont++){  // -1 porque ja ta na primeira.
        row = row->abaixo;  // percorre para baixo (linhas) ate achar a correta.
    }
    cont = 1;
    while (cont < j && row->direita->linha != -1){
        if (row->direita->coluna > novo->coluna){  // se a celula inserida esta a esquerda.
            novo->direita = row->direita;
            row->direita = novo;
        }
        else{
            row = row->direita;  // anda pelas celulas a direita.
        }
        cont++;
    }
    if (row->direita->linha == -1){  // a celula esta mais a direita.
        novo->direita = row->direita;  // aponta para a cabeça.
        row->direita = novo;  // ultima celula ou cabeca, senao tiver celulas, aponta para a celula.
    }
        


    // COLUNAS
    for (cont = 1; cont < j; cont++){  // -1 porque ja ta na primeira.
        column = column->direita;  // percorre a direita (colunas) ate achar a correta.
    }
    cont = 1;
    while (cont<i && column->abaixo->coluna != -1){ //anda pelas celulas ate achar a posicao
        if (column->abaixo->linha > novo->linha){
            novo->abaixo = column->abaixo;
            column->abaixo = novo;
        }
        else{
            column = column->abaixo; //anda pelas celulas abaixo
        }
        cont++;
    }
    if (column->abaixo->coluna == -1){
        novo->abaixo = column->abaixo; //aponta para a cabeca
        column->abaixo = novo; //ultima celula ou cabeca, senao tiver celulas, aponta para a celula
    }
}


void Matriz::imprime() {
    Node *row = head->abaixo;
    Node *column = head->direita;

    if(row != head && column != head) {
        Node *aux = row->direita;
        for(int i = 1; i <= auxLinha; i++) {
            for(int j = 1; j <= auxColuna; j++) {
                if(aux->linha == i && aux->coluna == j && aux != row){
                    cout << aux->valor << "\t";
                    aux = aux->direita;
                }
                else {
                    cout << 0 << "\t";
                }
                
            }
            row = row->abaixo;
            aux = row->direita;
            cout << "\n";
        }
    }
        
}


Matriz* Matriz::soma(Matriz *A, Matriz *B) {
    int i, j;
    double soma;
    Matriz* matC;
    Node *auxA, *auxB;

    if (A->auxLinha != B->auxLinha || A->auxColuna != B->auxColuna){ //soma de matrizes so é possivel qndo as duas forem de mesma ordem
        cout << "Nao é possivel somar!" << endl;
        return NULL;
    }

    if (!A || !B || !A->auxLinha || !A->auxColuna){
        return NULL;
    }

    matC = new Matriz;

    matC->auxLinha = A->auxLinha;
    matC->auxColuna = B->auxColuna;

    matC->newHeads(matC->auxLinha, matC->auxColuna);

    auxA = A->head->abaixo;
    auxB = B->head->abaixo;

    for (i = 1; i <= A->auxLinha; i++){
        for (j = 1; j <= A->auxColuna; j++){
            if (j == auxA->direita->coluna && j == auxB->direita->coluna){
                soma = auxA->direita->valor + auxB->direita->valor;
                //cout << soma << endl;
                matC->insere(i, j, soma);
                auxA = auxA->direita;
                auxB = auxB->direita;
            }
        }
        auxA = auxA->direita->abaixo;
        auxB = auxB->direita->abaixo;
    }

    return matC;
}

Matriz* Matriz::multiplica(Matriz *A, Matriz *B){
    int i=0, j=0, k=0;
    double total;
    Matriz *matC;
    Node *auxA, *auxB;

    if (A->auxLinha != B->auxColuna){ //so pode multiplicar se o numero de colunas de A eh igual ao numero de linhas de B
        cout << "Nao é possivel multiplicar!" << endl;        
        return NULL;
    }

    if (!A || !B || !A->auxLinha || !A->auxColuna || !B->auxColuna){
        return NULL;
    }

    matC = new Matriz; //C é formada pelo numero de linhas de A e de colunas de B
    matC->auxLinha = A->auxLinha;
    matC->auxColuna = B->auxColuna;
    matC->newHeads(matC->auxLinha, matC->auxColuna);

    auxA = A->head->abaixo;
    auxB = B->head->direita;

    for (i = 1; i <= A->auxLinha; i++){
        for (j = 1; j <= B->auxColuna; j++){
            total = 0;
            for (k = 1; k <= A->auxColuna; k++){
                total += auxMultiplicacao(A, i, k) * auxMultiplicacao(B, k, j); //chama a função auxMultiplicacao
            }
            if(total != 0){
                matC->insere(i, j, total);
            }        
        }
    }
    return matC;
}

//funcao encarregada por localizar o valor em determinada posição da matriz passada por parametro e o retorna
double Matriz::auxMultiplicacao(Matriz *mat, int linha, int coluna){
    Node *novo;
    int i = 0;

    novo = mat->head->direita;

    for (i = 0; i < coluna-1; i++){ //chega na coluna desejada
        novo = novo->direita;
    }

    do{
        novo = novo->abaixo;
        if (novo->linha == linha){
            return novo->valor;
        }
    }while(novo->coluna != -1);

    return 0; //elemento nao encontra
}