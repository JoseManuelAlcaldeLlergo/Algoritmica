#include "funciones_matematicas_estadisticas_ajuste.hpp"
#include "sistemaEcuaciones.hpp"
#include <iostream>

using namespace std;

double sumatorio(vector <double> x, vector <double> y, double expX, double expY){
	double suma=0;
	for(int i=0; i<x.size(); i++){
		suma+=pow(x[i],expX)*pow(y[i],expY);
	}
	return suma;
}

double calcularMedia(const vector <double> v){
	double res=0;
	for(int i=0; i<v.size();i++){
		res+=v[i];		
	}
	res=res/v.size();

	return res;
}

double calcularVarianza(const vector <double> v){
	double res=0;
	double media=calcularMedia(v);

	for(int i=0; i<v.size();i++){
		res+=pow(v[i]-media,2);
	}
	res=res/v.size();

	return res;
}

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados){
	double varReales;
	double varEstimados;

	varReales=calcularVarianza(tiemposReales);
	varEstimados=calcularVarianza(tiemposEstimados);

	return varEstimados/varReales;
}

double factorial(int n){
	double res=1;
	for(int i=1; i<=n;i++){
		res*=i;
	}
	return res;
}

void ajusteFactorial(const vector <double> &n, const vector <double> &t, double &a0, double &a1){

	vector <double> z;
	vector < vector < double > > A(2,vector<double>(2));
	vector < vector < double > > B(2,vector<double>(1));
	vector < vector < double > > X(2,vector<double>(1));

	z.clear();
	
	for(int i=0; i<n.size();i++){
		z.push_back(factorial(n[i]));
	}
	

	A[0][0]=z.size();
	A[0][1]=sumatorio(z,z,1,0);
	A[1][0]=sumatorio(z,z,1,0);
	A[1][1]=sumatorio(z,z,2,0);
	B[0][0]=sumatorio(t,t,1,0);
	B[1][0]=sumatorio(t,z,1,1);

	resolverSistemaEcuaciones(A, B, 2, X);
	a0=X[0][0];
	a1=X[1][0];


}

void calcularTiemposEstimadosFactorial(const vector <double> &n, const vector <double> &tiemposReales, const double &a0, const double &a1, vector<double> &tiemposEstimados){
	for(int i=0; i<n.size(); i++){
		tiemposEstimados.push_back(a0+(a1*factorial(n[i])));
	}
}

double calcularTiempoEstimadoFactorial(const double &n, const double &a0, const double &a1){
	return ((a0+a1*factorial(n))*(1.1574074074074074*pow(10,-11)));
}

void rellenaDatos(const vector <double> &n, const vector <double> &t, const vector <double> &te){
	ofstream fs("Datos.txt");
	for(int i=0; i<n.size(); i++){
		fs<<n[i]<<" "<<t[i]<<" "<<te[i]<<endl;
	}
	fs.close();

}