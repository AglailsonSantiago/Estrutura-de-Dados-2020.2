#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include "Matriz.h"
using namespace std;

int main() {
    Matriz *m1 = new Matriz;
    Matriz *m2 = new Matriz;
    // Matriz *c;
    // Matriz *d;
    Matriz *m3;
    Matriz *m4;

    cout << "\n/////////////////Matriz A/////////////////" << endl;

    m1->lerMatriz("A.txt");

    m1->imprime();

    cout << "\n/////////////////Matriz B/////////////////" << endl;

    m2->lerMatriz("B.txt");

    m2->imprime();

    cout << "\n///////////////Soma///////////////////" << endl;

    m3 = m3->soma(m1 ,m2);

    m3->imprime();

    cout << "\n////////////////Multiplicacao//////////////////" << endl;

    m4 = m4->multiplica(m1 ,m2);

    m4->imprime();

    cout << "\n";

    delete m1;
    delete m2;
    delete m3;
    delete m4;
}

