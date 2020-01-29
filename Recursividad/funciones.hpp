#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>


using namespace std;


typedef struct{
	int f;
	int c;
}Casilla;

int calculaCaminos(int fila, int col,vector <vector <Casilla> > &caminos, vector <Casilla> camino);
int calculaCaminosInvertido(int fila, int col,vector <vector <Casilla> > &caminos,vector <Casilla> camino);
void muestraTablero(vector <Casilla> camino);

void opcion1();


#endif