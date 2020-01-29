/***********************************
 * Autor: José Manuel Alcalde Llergo
 * Universidad de Córdoba (Spain)
 * 
 * ******************************************/

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>

using namespace std;
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <stdint.h> // Para usar uint64_t
#include <cassert>


void rellenarVector(vector<double> &v);

void estaOrdenado(const vector <double> &v);

int divide(vector<double> &v, int start, int end);

void quicksort(vector<double> &v, int start, int end);


  
#endif