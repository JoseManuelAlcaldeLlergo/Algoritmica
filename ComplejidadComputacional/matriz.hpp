/***********************************
 * Autor: José Manuel Alcalde Llergo
 * Universidad de Córdoba (Spain)
 * 
 * ******************************************/
#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <vector>
using namespace std;

void rellenarMatriz(vector<vector <double> > &m, int orden);

void imprimeMatriz(vector<vector <double> > &m, int orden);

void productoMatrices(const vector<vector <double> > m, const vector<vector <double> > m2,vector<vector <double> > &m3, const int orden);


#endif