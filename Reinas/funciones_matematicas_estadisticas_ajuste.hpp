#ifndef FUNCIONES_ESTADISTICAS_HPP
#define FUNCIONES_ESTADISTICAS_HPP

#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

double sumatorio(vector <double> x, vector <double> y, double expX, double expY);

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados);

double calcularMedia(const vector <double> v);

double calcularVarianza(const vector <double> v);

void ajusteFactorial(const vector <double> &n, const vector <double> &t, double &a0, double &a1);

void calcularTiemposEstimadosFactorial(const vector <double> &n, const vector <double> &tiemposReales, const double &a0, const double &a1, vector<double> &tiemposEstimados);

double calcularTiempoEstimadoFactorial(const double &n, const double &a0, const double &a1);

void rellenaDatos(const vector <double> &n, const vector <double> &t, const vector <double> &te);

double factorial(int n);
#endif