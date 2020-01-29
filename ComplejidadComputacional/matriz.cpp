#include "matriz.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include "funciones.hpp"
#include "sistemaEcuaciones.hpp"

using namespace std;

void rellenarMatriz(vector<vector <double> > &m, int orden){
	double n;

	for(int i=0; i<orden; i++){
		for(int j=0; j<orden; j++){
			n=(rand()%(106-95)+95);
			m[i][j]=n/100;
		}
	}
}

void imprimeMatriz(vector<vector <double> > &m, int orden){

	for(int i=0; i<orden; i++){
		for(int j=0; j<orden; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}

void productoMatrices(const vector<vector <double> > m, const vector<vector <double> > m2,vector<vector <double> > &m3, const int orden){

	for(int i=0; i<orden; i++){
		for(int j=0; j<orden; j++){
			for(int k=0; k<orden; k++){
				m3[i][j]= m3[i][j]+m[i][k]*m2[k][j];
			}
		}
	}
}


