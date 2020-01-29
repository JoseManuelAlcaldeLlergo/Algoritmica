#include <iostream>
#include <fstream>
#include "funciones.hpp"
#include <math.h>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "matriz.hpp"
#include "quicksort.hpp"
#include "strassen.hpp"
#include "ClaseTiempo.hpp"
#include "sistemaEcuaciones.hpp"



using namespace std;




void opcionQuicksort()
{
	int nmin, nmax, incremento, nrep;
	double a0, a1;
	vector<double> tiempos_reales;
	vector<double> tiempos_estimados;
	vector<double> n;
	vector<double> v;
	Clock c;
	double media=0;

	int x;

	cout<<"Introduzca el valor minimo de numero de elementos del vector: ";
	cin>>nmin;
	cout<<"Introduzca el valor maximo de numero de elementos del vector: ";
	cin>>nmax;
	cout<<"Introduzca el incremento de valor del numero de elementos: ";
	cin>>incremento;
	cout<<"Introduzca el numero de veces que se repetira la operacion: ";
	cin>>nrep;

	while(nmin<=nmax){
		cout<<"It"<<nmin<<endl;
		v.resize(nmin);
		n.push_back(nmin);
		for(int i=0; i<nrep; i++){
			rellenarVector(v);
			c.start();
			quicksort(v,0,nmin-1);
			estaOrdenado(v);
			c.stop();
			media+=c.elapsed();
		}
		tiempos_reales.push_back(media/nrep);
		media=0;
		nmin+=incremento;
		v.clear();
	}


	ajusteNlogN(n,tiempos_reales,a0,a1);
	calcularTiemposEstimadosNlogN(n,tiempos_reales,a0,a1, tiempos_estimados);

	rellenaDatos(n,tiempos_reales,tiempos_estimados);
	
	cout<<"La ecuacion de la recta es "<<a1<<"x + "<<a0<<endl;
	cout<<"El coeficiente de determinacion es de "<<calcularCoeficienteDeterminacion(tiempos_reales, tiempos_estimados)<<endl;
	do{
		cout<<"Introduzca el tamaño cuyo tiempo quiera estimar: ";
		cin>>x;
		if(x!=0){
			cout<<"El tiempo estimado para "<<x<<" elementos es "<<calcularTiempoEstimadoNlogN(x,a0,a1)<<" dias"<<endl;
			cout<<"Si desea finalizar el programa, introduzca tamaño 0"<<endl;
		}
	}while(x!=0);

}

void opcionProductoMatrices()
{
	vector<vector <double> > m(0, vector<double>(0));
	vector<vector <double> > m2(0, vector<double>(0));
	vector<vector <double> > m3(0, vector<double>(0));
	int nmin, nmax, incremento, nrep;
	vector<double> tiempos_reales;
	vector<double> tiempos_estimados;
	vector<double> n;
	vector<double> a;
	Clock c;
	int x;


	cout<<"Introduzca el valor minimo del orden de la matriz: ";
	cin>>nmin;
	cout<<"Introduzca el valor maximo del orden de la matriz: ";
	cin>>nmax;
	cout<<"Introduzca el incremento de valor del orden: ";
	cin>>incremento;


	while(nmin<=nmax){
		//cout<<"It"<<nmin<<endl;

		m.resize(nmin,vector<double>(nmin));
		m2.resize(nmin,vector<double>(nmin));
		m3.resize(nmin,vector<double>(nmin));
		n.push_back(nmin);
		
		rellenarMatriz(m,nmin);
		rellenarMatriz(m2,nmin);
		c.start();
		productoMatrices(m,m2,m3,nmin);
		c.stop();
		
		tiempos_reales.push_back(c.elapsed());
		nmin+=incremento;

		m.clear();
		m2.clear();
		m3.clear();
	}

	ajustePolinomico(n,tiempos_reales,a);

	calcularTiemposEstimadosPolinomico(n,tiempos_reales,a,tiempos_estimados);
	rellenaDatosMatriz(n,tiempos_reales,tiempos_estimados);

	cout<<"La ecuacion de la curva es "<<a[3]<<"x^3 + "<<a[2]<<"x^2 + "<<a[1]<<"x + "<<a[0]<<endl;
	cout<<"El coeficiente de determinacion es de "<<calcularCoeficienteDeterminacion(tiempos_reales, tiempos_estimados)<<endl;

	do{
		cout<<"Introduzca el tamaño cuyo tiempo quiera estimar: ";
		cin>>x;
		if(x!=0){
			cout<<"El tiempo estimado para "<<x<<" elementos es "<<calcularTiempoEstimadoPolinomico(x,a)<<" dias"<<endl;
			cout<<"Si desea finalizar el programa, introduzca tamaño 0"<<endl;
		}
	}while(x!=0);
	

}

void opcionStrassen()
{
	vector<vector <double> > m(0, vector<double>(0));
	vector<vector <double> > m2(0, vector<double>(0));
	vector<vector <double> > m3(0, vector<double>(0));
	unsigned int nmin, nmax;
	vector<double> tiempos_reales;
	vector<double> tiempos_estimados;
	vector<double> n;
	vector<double> a;
	Clock c;
	int x;


	cout<<"Introduzca el valor minimo del orden de la matriz (debe ser una potencia de 2): ";
	cin>>nmin;
	cout<<"Introduzca el valor maximo del orden de la matriz (debe ser una potencia de 2): ";
	cin>>nmax;



	while(nmin<=nmax){
		//cout<<"It"<<nmin<<endl;

		m.resize(nmin,vector<double>(nmin));
		m2.resize(nmin,vector<double>(nmin));
		m3.resize(nmin,vector<double>(nmin));
		n.push_back(nmin);
		
		rellenarMatriz(m,nmin);
		rellenarMatriz(m2,nmin);
		c.start();
		strassen(m,m2,m3,nmin);
		c.stop();
		
		tiempos_reales.push_back(c.elapsed());
		nmin*=2;

		m.clear();
		m2.clear();
		m3.clear();
	}

	ajustePolinomicoStrassen(n,tiempos_reales,a);

	calcularTiemposEstimadosPolinomicoStrassen(n,tiempos_reales,a,tiempos_estimados);
	rellenaDatosStrassen(n,tiempos_reales,tiempos_estimados);

	cout<<"La ecuacion de la curva es "<<a[3]<<"x^3 + "<<a[2]<<"x^2 + "<<a[1]<<"x + "<<a[0]<<endl;
	cout<<"El coeficiente de determinacion es de "<<calcularCoeficienteDeterminacion(tiempos_reales, tiempos_estimados)<<endl;

	do{
		cout<<"Introduzca el tamaño cuyo tiempo quiera estimar: ";
		cin>>x;
		if(x!=0){
			cout<<"El tiempo estimado para "<<x<<" elementos es "<<calcularTiempoEstimadoPolinomico(x,a)<<" dias"<<endl;
			cout<<"Si desea finalizar el programa, introduzca tamaño 0"<<endl;
		}
	}while(x!=0);
	

}



void imprimeVector(vector<double> v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}




double sumatorio(vector <double> x, vector <double> y, double expX, double expY){
	double suma=0;
	for(int i=0; i<x.size(); i++){
		suma+=pow(x[i],expX)*pow(y[i],expY);
	}
	return suma;
}



double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales, const vector <double> &tiemposEstimados){
	double varReales=0;
	double varEstimados=0;
	double mediaReales=0;
	double mediaEstimados=0;

	for(int i=0; i<tiemposReales.size();i++){
		mediaReales+=tiemposReales[i];
		mediaEstimados+=tiemposEstimados[i];
	}
	mediaReales=mediaReales/tiemposReales.size();
	mediaEstimados=mediaEstimados/tiemposEstimados.size();

	for(int i=0; i<tiemposReales.size(); i++){
		varReales+=pow(tiemposReales[i]-mediaReales,2);
		varEstimados+=pow(tiemposEstimados[i]-mediaEstimados,2);
	}
	varReales=varReales/tiemposReales.size();
	varEstimados=varEstimados/tiemposEstimados.size();

	return varEstimados/varReales;
}


//APARTADO 1
void rellenaDatos(const vector <double> &n, const vector <double> &t, const vector <double> &te){
	ofstream fs("Datos.txt");
	for(int i=0; i<n.size(); i++){
		fs<<n[i]<<" "<<t[i]<<" "<<te[i]<<endl;
	}
	fs.close();

}

void calcularTiemposEstimadosNlogN(const vector <double> &n, const vector <double> &tiemposReales, const double &a0, const double &a1, vector<double> &tiemposEstimados){
	for(int i=0; i<n.size(); i++){
		tiemposEstimados.push_back(a0+a1*n[i]*log(n[i]));
	}
}
double calcularTiempoEstimadoNlogN(const double &n, const double &a0, const double &a1){
	return (((a0+n*log(n)*a1))*(1.1574074074074074*pow(10,-11)));
}

void ajusteNlogN(const vector <double> &n, const vector <double> &t, double &a0, double &a1){

	vector <double> z;
	vector < vector < double > > A(2,vector<double>(2));
	vector < vector < double > > B(2,vector<double>(1));
	vector < vector < double > > X(2,vector<double>(1));

    //Cambio de variable
	for(int i=0; i<n.size();i++){
		z.push_back(n[i]*log(n[i]));
	}

    //Rellenamos las matrices del sistema
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

//APARTADO 2

void rellenaDatosMatriz(const vector <double> &n, const vector <double> &t, const vector <double> &te){
	ofstream fs("DatosMatriz.txt");
	for(int i=0; i<n.size(); i++){
		fs<<n[i]<<" "<<t[i]<<" "<<te[i]<<endl;
	}
	fs.close();

}

void calcularTiemposEstimadosPolinomico(const vector <double> &n, const vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados){
	tiemposEstimados.clear();
	for(int i=0; i<n.size(); i++){
		tiemposEstimados.push_back(a[0]+a[1]*n[i]+a[2]*pow(n[i],2)+a[3]*pow(n[i],3));
	}
}

double calcularTiempoEstimadoPolinomico(const double &n, const vector <double> &a){
	return((a[0]+a[1]*n+a[2]*pow(n,2)+a[3]*pow(n,3))*(1.1574074074074074*pow(10,-11)));
}


void ajustePolinomico(const vector <double> &n, const vector <double> &t,vector<double> &a){

	vector < vector < double > > A(4,vector<double>(4));
	vector < vector < double > > B(4,vector<double>(1));
	vector < vector < double > > X(4,vector<double>(1));


	A[0][0]=n.size();
	A[0][1]=sumatorio(n,n,1,0);
	A[0][2]=sumatorio(n,n,2,0);
	A[0][3]=sumatorio(n,n,3,0);
	A[1][0]=sumatorio(n,n,1,0);
	A[1][1]=sumatorio(n,n,2,0);
	A[1][2]=sumatorio(n,n,3,0);
	A[1][3]=sumatorio(n,n,4,0);
	A[2][0]=sumatorio(n,n,2,0);
	A[2][1]=sumatorio(n,n,3,0);
	A[2][2]=sumatorio(n,n,4,0);
	A[2][3]=sumatorio(n,n,5,0);
	A[3][0]=sumatorio(n,n,3,0);
	A[3][1]=sumatorio(n,n,4,0);
	A[3][2]=sumatorio(n,n,5,0);
	A[3][3]=sumatorio(n,n,6,0);
	B[0][0]=sumatorio(t,t,1,0);
	B[1][0]=sumatorio(t,n,1,1);
	B[2][0]=sumatorio(n,t,2,1);
	B[3][0]=sumatorio(n,t,3,1);

	resolverSistemaEcuaciones(A, B, 4, X);

	//Rellenamos el vector de coeficientes con las soluciones del sistema
	a.clear();
	for(int i=0; i<4; i++){
		a.push_back(X[i][0]);
	}
}


//APARTADO 3
void rellenaDatosStrassen(const vector <double> &n, const vector <double> &t, const vector <double> &te){
	ofstream fs("DatosStrassen.txt");
	for(int i=0; i<n.size(); i++){
		fs<<n[i]<<" "<<t[i]<<" "<<te[i]<<endl;
	}
	fs.close();
}

void calcularTiemposEstimadosPolinomicoStrassen(const vector <double> &n, const vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados){
	tiemposEstimados.clear();
	for(int i=0; i<n.size(); i++){
		tiemposEstimados.push_back(a[0]+a[1]*n[i]+a[2]*pow(n[i],2)+a[3]*pow(n[i],2.81));
	}
}

double calcularTiempoEstimadoPolinomicoStrassen(const double &n, const vector <double> &a){
	return((a[0]+a[1]*n+a[2]*pow(n,2)+a[3]*pow(n,2.81))*(1.1574074074074074*pow(10,-11)));
}

void ajustePolinomicoStrassen(const vector <double> &n, const vector <double> &t, vector<double> &a){
        vector < vector < double > > A(4,vector<double>(4));
    vector < vector < double > > B(4,vector<double>(1));
    vector < vector < double > > X(4,vector<double>(1));


    A[0][0]=n.size();
    A[0][1]=sumatorio(n,n,1,0);
    A[0][2]=sumatorio(n,n,2,0);
    A[0][3]=sumatorio(n,n,2.81,0);
    A[1][0]=sumatorio(n,n,1,0);
    A[1][1]=sumatorio(n,n,2,0);
    A[1][2]=sumatorio(n,n,2,1);
    A[1][3]=sumatorio(n,n,2.81,1);
    A[2][0]=sumatorio(n,n,2,0);
    A[2][1]=sumatorio(n,n,1,2);
    A[2][2]=sumatorio(n,n,2,2);
    A[2][3]=sumatorio(n,n,2.81,2);
    A[3][0]=sumatorio(n,n,2.81,0);
    A[3][1]=sumatorio(n,n,1,2.81);
    A[3][2]=sumatorio(n,n,2,2.81);
    A[3][3]=sumatorio(n,n,2.81,2.81);
    B[0][0]=sumatorio(t,t,1,0);
    B[1][0]=sumatorio(n,t,1,1);
    B[2][0]=sumatorio(n,t,2,1);
    B[3][0]=sumatorio(n,t,2.81,1);

    resolverSistemaEcuaciones(A, B, 4, X);

    //Rellenamos el vector de coeficientes con las soluciones del sistema
    a.clear();
    for(int i=0; i<4; i++){
        a.push_back(X[i][0]);
    }
    cout<<"a0="<<a[0]<<"\na1="<<a[1]<<"\na2="<<a[2]<<"\na3="<<a[3]<<endl;
}
