#include <iostream>
#include "opciones.hpp"
#include "funciones.hpp"
#include <vector>
#include <cstdio>


using namespace std;




void opcion1(){

	int col, ncaminos;
	vector <vector <Casilla> > caminos;
	vector <Casilla> camino;
	char c;

	cout<<"Introduzca la columna a la que quiere llegar: ";
	cin>>col;

	ncaminos=calculaCaminos(8,col,caminos,camino);


	cout<<"Hay "<<ncaminos<<" caminos"<<endl;

	
	cin.ignore();
	for(int i=0; i<caminos.size();i++){
		cout<<"Camino "<<i+1<<":"<<endl;
		for(int k=caminos[i].size()-1; k>=0;k--){
			cout<<"("<<caminos[i][k].f<<", "<<caminos[i][k].c<<");";
		}
		cout<<endl<<endl<<"\t        TABLERO "<<i+1<<": "<<endl;
		muestraTablero(caminos[i]);
		do{
			cout<<"Presione ENTER para continuar..."<<endl;
			c=getchar();
		}while(c!=13 && c!=10 && c!=141);
	}

}

void opcion2(){

	int ncaminos;
	vector <vector <Casilla> > caminos;
	vector <Casilla> camino;
	vector <vector <string> > tablero(8, vector <string> (8));
	char c;


	ncaminos=calculaCaminosInvertido(1,2,caminos,camino);


	cout<<"Hay "<<ncaminos<<" caminos"<<endl;

	cin.ignore();
	for(int i=0; i<caminos.size();i++){
		cout<<"Camino "<<i+1<<":"<<endl;
		for(int k=0; k<caminos[i].size();k++){
			cout<<"("<<caminos[i][k].f<<", "<<caminos[i][k].c<<");";
		}
		cout<<endl<<endl<<"\t        TABLERO "<<i<<": "<<endl;
		muestraTablero(caminos[i]);
		do{
			cout<<"Presione ENTER para continuar..."<<endl;
			c=getchar();
		}while(c!=13 && c!=10 && c!=141);
	}
}


void opcion3(){

	int ncaminos;
	vector <vector <Casilla> > caminos;
	vector <Casilla> camino;
    char c;

	ncaminos=calculaCaminosInvertido(1,7,caminos,camino);

	cout<<"Hay "<<ncaminos<<" caminos"<<endl;

	cin.ignore();
	for(int i=0; i<caminos.size();i++){
		cout<<"Camino "<<i+1<<":"<<endl;
		for(int k=0; k<caminos[i].size();k++){
			cout<<"("<<caminos[i][k].f<<", "<<caminos[i][k].c<<");";
		}
		cout<<endl<<endl<<"\t        TABLERO "<<i<<": "<<endl;
		muestraTablero(caminos[i]);
		do{
			cout<<"Presione ENTER para continuar..."<<endl;
			c=getchar();
		}while(c!=13 && c!=10 && c!=141);
	}
}