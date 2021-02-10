#ifndef PONTO_H
#define PONTO_H

struct Ponto; // Declaracao do Tipo de dado exportado

// Aloca e retorna um ponto com coordenadas (x,y)
Ponto *pto_cria(double x, double y); 

// Libera a memoria de um ponto previamente criado
void pto_libera(Ponto* p); 

// getters: retornam os valores das coordenadas de um ponto 
double pto_getX(Ponto *p);
double pto_getY(Ponto *p);

// setters: atribuem novos valores as coordenadas de um ponto 
void pto_setX(Ponto *p, double x);
void pto_setY(Ponto *p, double y);

// Retorna a distancia entre dois pontos
double pto_distancia(Ponto* p1, Ponto* p2);

#endif 