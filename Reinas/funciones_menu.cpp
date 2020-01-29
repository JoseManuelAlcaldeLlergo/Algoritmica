#include "funciones_menu.hpp"
#include "funciones_backtracking.hpp"
#include "funciones_probabilistas.hpp"
#include "funciones_reinas.hpp"
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <cstdio> //getchar
#include "ClaseTiempo.hpp"
#include "funciones_matematicas_estadisticas_ajuste.hpp"


using namespace std;

void opc_Backtracking(){

	int nreinas, optMostrar=0;
	vector <vector <int> > soluciones;
	char c=0;

	cout<<"Introduzca el número de reinas: ";
	cin>>nreinas;

	nReinasBacktracking(nreinas,soluciones);

	cout<<"Hay "<<soluciones.size()<<" soluciones"<<endl;



	do{
		cout<<"\n¿Quiere mostrar los tableros con las soluciones?\n\t1-Si\n\t2-No\nOpcion: ";
		cin>>optMostrar;
		switch(optMostrar){
			case 1:
				for(int i=0; i<soluciones.size();i++){

					cout<<endl<<endl<<"\t        TABLERO "<<i+1<<": "<<endl;
					muestraTablero(soluciones[i],nreinas);

					if(i==0) c=getchar();
					
					do{
						cout<<"Presione ENTER para continuar..."<<endl;
						c=getchar();
					}while(c!=13 && c!=10 && c!=141);
				}
				break;
			case 2:
				break;
			default:
				cout<<"Opcion no válida, introduzca el numero de la opcion correspondiente"<<endl;
				break;

		}
	}while(optMostrar!=1&&optMostrar!=2);

}

void opc_Probabilista(){

	int nreinas, optMostrar=0;
	bool exito=false;
	vector <int> posiciones;
	int cont=0;
	srand(time(NULL));

	cout<<"Introduzca el número de reinas: ";
	cin>>nreinas;


	while(!exito){
		nReinasLasVegas(nreinas,posiciones,exito);
		cont++;
	}
	cout<<"Solución:"<<endl;
	for(int i=1; i<=nreinas;i++){
		cout<<posiciones[i];
		if(i!=nreinas){ cout<<", ";}
	}
	cout<<endl;
	
	cout<<"\nHa necesitado "<<cont<<" intentos para alcanzar la solución"<<endl;
	do{
		cout<<"\n¿Quiere mostrar el tablero con la solución?\n\t1-Si\n\t2-No\nOpcion: ";
		cin>>optMostrar;
		switch(optMostrar){
			case 1:
				muestraTablero(posiciones,nreinas);
				break;
			case 2:
				break;
			default:
				cout<<"Opcion no válida, introduzca el numero de la opcion correspondiente"<<endl;
				break;

		}
	}while(optMostrar!=1&&optMostrar!=2);
	


}

void opc_calculaTiemposReinasBacktracking(){
	vector <vector <int> > soluciones;
	int nmin, nmax, incremento;
	vector <double> tiempos_reales;
	vector <double> tiempos_estimados;
	vector <double> n;
	double a0, a1;
	Clock c;
	double x;


	cout<<"Introduzca el número mínimo de reinas: ";
	cin>>nmin;
	cout<<"Introduzca el número máximo de reinas: ";
	cin>>nmax;
	cout<<"Introduzca el incremento de las reinas: ";
	cin>>incremento;


	while(nmin<=nmax){
		cout<<"Tamaño "<<nmin<<"..."<<endl;

		soluciones.clear(); //Vaciamos la matriz de soluciones para las distintas iteraciones
		n.push_back(nmin);
		
		c.start();
		nReinasBacktracking(nmin,soluciones);
		if(c.isStarted()){
			c.stop();
		}
		else{
			cout<<"ERROR reloj no iniciado"<<endl;
		}

		tiempos_reales.push_back(c.elapsed());
		nmin+=incremento;

	}

	ajusteFactorial(n,tiempos_reales,a0,a1);

	calcularTiemposEstimadosFactorial(n,tiempos_reales,a0,a1,tiempos_estimados);

	rellenaDatos(n,tiempos_reales,tiempos_estimados);

	cout<<"\nEl coeficiente de determinacion es de "<<calcularCoeficienteDeterminacion(tiempos_reales, tiempos_estimados)<<endl;

	cout<<"\nLa ecuacion de la recta es "<<a1<<"*factorial(x) + "<<a0<<endl;

	do{
		cout<<"\nIntroduzca el tamaño cuyo tiempo quiera estimar: ";
		cin>>x;
		if(x!=0){
			cout<<"\nEl tiempo estimado para "<<x<<" elementos es "<<calcularTiempoEstimadoFactorial(x,a0,a1)<<" dias"<<endl;
			cout<<"\nSi desea finalizar el programa, introduzca tamaño 0."<<endl;
		}
	}while(x!=0);

	n.clear();
	tiempos_estimados.clear();
	tiempos_reales.clear();
}

void opc_comparaAlgoritmosReinas(){

	Clock cBack, cVeg;
	vector <vector <int> > soluciones;
	vector <int> posiciones;
	bool exito=false;
	double cociente,back,veg;
	int limite=28;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\tN-reinas"<<"\t"<<"BACTRACKING(microseg)"<<"\t"<<"   VEGAS(microseg)"<<"\t\tRelacion(Tbacktracking/Tvegas)"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
	
	for(int i=8; i<limite; i++){ //He puesto hasta 27 porque a partir de ahi empieza a tardar bastante
		soluciones.clear();
		posiciones.clear();
		cBack.start();
		nReinasBacktracking(i,soluciones,true);
		cBack.stop();
		cVeg.start();
		nReinasLasVegas(i,posiciones,exito);
		cVeg.stop();
		back=cBack.elapsed();
		veg=cVeg.elapsed();
		cociente=back/veg;

		cout<<"\t   "<<i<<"\t\t\t"<<cBack.elapsed()<<"\t\t\t"<<cVeg.elapsed()<<"\t\t\t     "<<cociente<<endl;
	}

}