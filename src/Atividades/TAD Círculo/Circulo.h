#ifndef CIRCULO_H
#define CIRCULO_H
#include "Ponto.h"

struct Circulo; // Declaracao do Tipo de dado exportado

// Aloca e retorna um struct Circulo
Circulo *circ_cria(double raio, Ponto *centro);

// Libera a memoria que foi alocada para o struct Circulo
void circ_libera(Circulo *c);

// setters
void circ_setRaio(Circulo *c, double raio);
void circ_setCentro(Circulo *c, Ponto *p);
void circ_setX(Circulo *c, double x); // coordenada x do centro do Circulo c
void circ_setY(Circulo *c, double y); // coordenada y do centro do Circulo c

// getters
double circ_getRaio(Circulo *c);
Ponto *circ_getCentro(Circulo *c);
double circ_getX(Circulo *c); // coordenada x do centro do Circulo c
double circ_getY(Circulo *c); // coordenada y do centro do Circulo c

// Retorna a area do Circulo c
double circ_getArea(Circulo *c);

// Recebe um Ponto p e um Circulo c e retorna:
// true: se o ponto esta contido no circulo;
// false: caso contrario.
bool circ_interior(Circulo *c, Ponto *p);

#endif