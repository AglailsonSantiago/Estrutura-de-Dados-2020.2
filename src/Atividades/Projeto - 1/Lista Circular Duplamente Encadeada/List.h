#ifndef LIST_H
#define LIST_H

struct Node;

class List {

private:
// Ponteiro para o no cabeca da lista
Node *head;

public:
    // Basicamente é parecida da implementação da lista simplesmente encadeada, 
    // onde se tem a cabeça recebendo um novo Nó, a única modificação feita foi 
    // para manter a circularidade, que consiste basicamente em fazer o next e o 
    // back da cabeça apontar para a própria cabeça, e com isso foi feito o construtor.
    List(); 


    // Para o destrutor usamos a função clear(), e após isso apagamos o Nó cabeça 
    // para finalizar a lista, a função clear() tem um laço que percorre cada Nó 
    // a partir do último e vai deletando até chegar no Nó cabeça. Apesar de não 
    // parecer, o destrutor tem uma complexidade, porque usa a chamada do clear(), 
    // com isso temos uma operação de complexidade O(n).
    ~List(); 


    // Essa operação consiste em adicionar um elemento ao final da lista, isso se
    // torna uma operação bem simples visto que não precisamos percorrer toda a lista 
    // para chegar até o último elemento, como o Nó sempre contém um anterior e um 
    // próximo, podemos pegar o último através do do anterior do head, para isso foi
    // criando um Node auxiliar que garante esse último Nó, assim depois podemos fazer 
    // as operações normalmente de inserção, lembrando sempre de depois fazer o novo 
    // elemento apontar para o head, para garantir a circularidade. Como se trata de 
    // uma operação bem simples, temos uma complexidade O(1).
    void push_back(int key);



    // Bem parecido com as operações realizadas no push_back(), a diferença é que 
    // agora queremos remover o último elemento, com isso temos um Node auxiliar chamado
    // penúltimo que aponta para o penúltimo elemento da lista, assim temos dois ponteiros, 
    // um para o último e um para o penúltimo para facilitar nossas operações, com isso 
    // podemos apagar o último tranquilamente e fazer o penúltimo apontar para a cabeça 
    // para manter a circularidade, da mesma forma do push, temos uma operação bem simples, 
    // sem a necessidade de percorrer a lista, com isso temos uma complexidade O(1).
    int pop_back();


    // Por se tratar de uma inserção após determinada posição específica, se torna um 
    // pouco mais complexo, visto que, se por exemplo tivermos uma posição no meio da 
    // lista não teríamos como acessá-la facilmente, com isso foi necessário criar um 
    // laço que percorre a lista e verifica a posição de cada elemento, começando no 1 
    // até o size() que é o tamanho da lista, com isso a cada incremento do laço verificamos 
    // se a posição é igual aquela que foi passada como parâmetro, se isso acontecer inserimos 
    // o elemento no próximo, fazendo esses ajustes com auxílio de um Node auxiliar e um próximo, 
    // por último temos um caso que não pode ser esquecido, que é caso o elemento a ser inserido 
    // seja na última posição da lista, o qual foi preciso realizar um tratamento específico, 
    // visto que após inserir o novo ultimo, precisávamos fazer ele apontar para a cabeça para 
    // manter a circularidade. Em relação a complexidade, como citado, foi necessário o uso de um 
    // laço e da chamada da função size(), que também contém outro laço que percorre a lista, com 
    // isso temos uma operação O(n^2).
    void insertAfter(int key, int k);


    // Não se trata de uma operação muito difícil, porém precisamos percorrer a lista 
    // da cabeça até o último elemento, verificando se o valor é igual a key passada 
    // por parâmetro, se for, guardamos o valor do próximo elemento, deletamos o que 
    // encontramos, e ajustamos os ponteiros, afim de ligar o anterior e o próximo, 
    // com isso damos um break, já que queremos remover apenas um deles, por fim 
    // incrementamos o auxiliar. Por ser necessário percorrer a lista encontrando 
    // o elemento, temos uma operação com complexidade O(n).
    void remove(int key);
    

    // Operação bem parecida como o remove(), no caso temos o mesmo código, a única 
    // diferença é que não temos o break, com isso ele continua buscando e removendo 
    // os elementos iguais a key que ele encontrar na lista, por ser o mesmo código, 
    // temos uma complexidade O(n).
    void removeAll(int key);
    

    // Essa operação não tem muito oque fazer além de percorrer a lista e imprimir 
    // o valor de cada Nó, e é isso que fazemos após verificar se é diferente de 
    // vazia, percorremos a lista até o size(), que é um inteiro que retorna o tamanho 
    // da lista, assim imprimindo os nó, vale ressaltar que como usamos a operação size(), 
    // que também percorre a lista, no fim vamos ter uma complexidade O(n²), pois iremos 
    // percorrer a lista duas vezes.
    void print();


    // Bem parecido com o print(), a única diferença é que iremos percorrer do fim 
    // para o início, até chegar na cabeça, assim vamos imprimir em ordem reversa, 
    // como se trata das mesmas condições do print(), temos também uma complexidade de O(n²).
    void printReverse();
    

    // Operação bem simples, basicamente verifica o próximo a cabeça aponta para 
    // cabeça e o back da cabeça aponta para cabeça, assim retornando true, significando 
    // que a lista está vazia, se caso isso não ocorra retorna false, significando que a 
    // lista tem elementos, por ser simples sem a necessidade de percorrer nada que envolva 
    // N elementos, temos uma complexidade O(1).
    bool empty();
    

    // Como já foi explicado em outras operações, essa operação basicamente percorre 
    // a lista até o último elemento, para isso usamos um contador que irá contar 
    // e depois retornar quantos elementos a lista possui, como foi necessário percorrer 
    // a lista com N elementos, temos uma complexidade de O(n).
    int size();


    // Como também já foi explicado no destrutor, essa operação apaga todos os 
    // elementos até chegar ao Nó cabeça, para isso usamos um Node auxiliar 1 que 
    // inicia no começo da lista e percorre cada elemento, deletando e passando 
    // para o próximo, até chegar na cabeça, também foi necessário criar um auxiliar 2
    // que guarda o auxiliar 1 para não perde-lo, ressaltando que após isso devemos 
    // sempre fazer o próximo e anterior da cabeça apontarem para a cabeça para 
    // mantermos a circularidade na lista, assim encerramos a função com a complexidade 
    // O(n), visto que nela também foi preciso percorrer os N elementos da lista.
    void clear();


    // Existem diversas formas de concatenar, mas tentamos utilizar a mais simples 
    // delas que é percorrer as duas listas, a principal e a passada por parâmetro, 
    // afim de chegar até o último elemento de ambas, ao chegar no final da lista lst, 
    // precisamos fazer os ajustes de ponteiro, como fazer o último apontar para cabeça 
    // da lista principal, e o primeiro da lst apontar para o último da principal, 
    // assim vamos criando a lista e concatenando, por fim fazemos o próximo e o anterior 
    // da lista lst apontar para própria cabeça, assim ficando fazia e mantendo a circularidade, 
    // restando apenas o Nó cabeça. Como dito, existem diversas formas de fazer, creio que 
    // apenas um laço resolveria o problema, mas como usamos dois para melhor entendimento, 
    // temos uma complexidade O(n²).
    void concat(List *lst);


    // Como queremos apenas criar uma cópia da lista, a primeira coisa que fizemos 
    // foi criar uma New list e um Node auxiliar que irá ajudar a percorrer a lista, 
    // assim percorremos a lista até o final, e chamamos o push_back() passando sempre 
    // o valor do próximo, posteriormente fazemos o aux caminhar na lista, assim facilitando 
    // as operações, visto que o push_back() sempre vai inserir no fim da lista, por fim ao 
    // retornar a lista que foi criada, teremos uma cópia dela. Como foi necessário percorrer 
    // a lista novamente com N elementos até o final dela, portanto usamos a operação size(), 
    // que também percorre a lista até o final dela, com isso temos uma complexidade O(n²), 
    // já que foi necessário percorrer a lista duas vezes na mesma operação.
    List *copy();


    // Nesta operação, queremos apenas inserir na lista oque contem no array passado 
    // por parâmetro, então foi necessário percorrer esse array ate o N elemento dele, 
    // que foi passado por parâmetro, e inserindo os valores das posições utilizando a 
    // operação push_back(), apenas isso, os ajustes de ponteiro e circularidade já 
    // são feitos dentro do pus_back(), então não foi preciso realizar novamente, assim 
    // temos uma complexidade O(n), já que foi necessário a utilização de laço que percorre 
    // a quantidade de elementos a ser inserida. 
    void copyArray(int n, int arr[]);
    

    // Nessa operação tivemos sempre pensar nas duas listas, no caso criamos um 
    // auxiliar para cada uma e percorremos as duas ao mesmo tempo dentro de um único 
    // laço, para evitar criar outro laço, com isso já verificamos se o primeiro valor 
    // da primeira lista é diferente do primeiro da segunda lista, se for já retornamos 
    // um false e vamos percorrendo fazendo essa verificação, depois do laço verificamos 
    // se os dois apontam para a cabeça, se sim, significa que as listas são iguais, 
    // então retorna verdade, caso contrário será falso, dessa forma conseguimos verificar 
    // as listas, como foi utilizado apenas um único laço para fazer essa verificação, 
    // temos uma complexidade de O(n).
    bool equal(List *lst);

};

#endif