/***********************************
 * Autor: José Manuel Alcalde Llergo
 * Universidad de Córdoba (Spain)
 * 
 * ******************************************/

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <iostream>

using namespace std;



void opcionProductoMatrices();

void opcionQuicksort();

void opcionStrassen();

void imprimeVector(const vector <double> v);


double sumatorio(vector <double> x, vector <double> y, double expX, double expY);


double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados);


//APARTADO 1
void rellenaDatos(const vector <double> &n, const vector <double> &t, const vector <double> &te);

void calcularTiemposEstimadosNlogN(const vector <double> &n, const vector <double> &tiemposReales, const double &a0, const double &a1, vector<double> &tiemposEstimados);

double calcularTiempoEstimadoNlogN(const double &n, const double &a0, const double &a1);

void ajusteNlogN(const vector <double> &n, const vector <double> &t, double &a0, double &a1);



//APARTADO 2

void rellenaDatosMatriz(const vector <double> &n, const vector <double> &t, const vector <double> &te);

void calcularTiemposEstimadosPolinomico(const vector <double> &n, const vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados);

double calcularTiempoEstimadoPolinomico(const double &n, const vector <double> &a);

void ajustePolinomico(const vector <double> &n, const vector <double> &t, vector<double> &a);


//APARTADO 3
void rellenaDatosStrassen(const vector <double> &n, const vector <double> &t, const vector <double> &te);

void calcularTiemposEstimadosPolinomicoStrassen(const vector <double> &n, const vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados);

double calcularTiempoEstimadoPolinomicoStrassen(const double &n, const vector <double> &a);

void ajustePolinomicoStrassen(const vector <double> &n, const vector <double> &t, vector<double> &a);




#endif