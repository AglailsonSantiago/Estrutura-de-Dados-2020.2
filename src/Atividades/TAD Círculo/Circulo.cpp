// Implementar
#include <iostream>
#include <cmath>
#include "Circulo.h"
#include "Ponto.h"
using namespace std ;

struct Circulo{
    double raio;
    Ponto *centro;
    double xCentro;
    double yCentro;
};


Circulo *circ_cria(double raio, Ponto *centro){
    Circulo *c = new (nothrow) Circulo;
    if(c == nullptr){
        cerr << "Memória insuficiente" << endl;
        return nullptr;
    }
    c->raio = raio;
    c->centro = centro;
    c->xCentro = pto_getX(centro);
    c->yCentro = pto_getY(centro);
    return c;
}

void circ_setRaio(Circulo *c, double raio){
    c->raio = raio;
}

void circ_setCentro(Circulo *c, Ponto *p){
    circ_setX(c, pto_getX(p));
    circ_setY(c, pto_getY(p));
    c->centro = p;  
}

void circ_setX(Circulo *c, double x){
    pto_setX(c->centro, x);
    c->xCentro = x;
}

void circ_setY(Circulo *c, double y){
    pto_setY(c->centro, y);
    c->yCentro = y;
}

double circ_getRaio(Circulo *c){
    return c->raio;
}

Ponto *circ_getCentro(Circulo *c){
    return c->centro;
}

double circ_getX(Circulo *c){
    return c->xCentro;
}

double circ_getY(Circulo *c){
    return c->yCentro;
}

double circ_getArea(Circulo *c){
    return M_PI*c->raio*c->raio;
}

bool circ_interior(Circulo *c, Ponto *p){
    if(pto_distancia(c->centro, p) <= c->raio){
       // cout << pto_distancia(c->centro, p);
        return 1;
    }
    else{
        return 0;
    }
}

void circ_libera(Circulo *c){
    if(c != nullptr) {
        delete c;
        pto_libera(c->centro);
        cout << "circulo liberado" << endl;
        
    }
}