#include <iostream>
#include "funciones.hpp"


using namespace std;


	//vector <Casilla> camino;
int calculaCaminos(int fila, int col,vector <vector <Casilla> > &caminos,vector <Casilla> camino){

	Casilla dest;
	dest.f=fila;
	dest.c=col;
	vector <Casilla> aux;
	

	//Descarto los casos absurdos, es decir, cuando el caballo se sale del tablero
	if(dest.f<1 || dest.f>8 || dest.c<1 || dest.c>8){
		return 0;
	}
	else{
		//Si estoy en la fila 1 solo hay una opción de llegar
		if(dest.f==1){
			//cout<<"Casilla: ("<<dest.f<<","<<dest.c<<")"<<endl;
			//camino.pop_back();
			camino.push_back(dest);
			caminos.push_back(camino);
			camino.clear();
			return 1;
		}
		//Aplico el caso general
		else{
			//cout<<"Casilla: ("<<dest.f<<","<<dest.c<<")"<<endl;
			camino.push_back(dest);
			return calculaCaminos(dest.f-1,dest.c-2,caminos,camino)+calculaCaminos(dest.f-1,dest.c+2,caminos,camino)+calculaCaminos(dest.f-2,dest.c+1,caminos,camino)+calculaCaminos(dest.f-2,dest.c-1,caminos,camino);
		}
	}

}

int calculaCaminosInvertido(int fila, int col,vector <vector <Casilla> > &caminos,vector <Casilla> camino){

	Casilla dest;
	dest.f=fila;
	dest.c=col;
	vector <Casilla> aux;
	

	//Descarto los casos absurdos, es decir, cuando el caballo se sale del tablero
	if(dest.f<1 || dest.f>8 || dest.c<1 || dest.c>8){
		return 0;
	}
	else{
		//Si estoy en la fila 1 solo hay una opción de llegar
		if(dest.f==8){
			//cout<<"Casilla: ("<<dest.f<<","<<dest.c<<")"<<endl;
			//camino.pop_back();
			camino.push_back(dest);
			caminos.push_back(camino);
			camino.clear();
			return 1;
		}
		//Aplico el caso general
		else{
			//cout<<"Casilla: ("<<dest.f<<","<<dest.c<<")"<<endl;
			camino.push_back(dest);
			return calculaCaminosInvertido(dest.f+1,dest.c-2,caminos,camino)+calculaCaminosInvertido(dest.f+1,dest.c+2,caminos,camino)+calculaCaminosInvertido(dest.f+2,dest.c+1,caminos,camino)+calculaCaminosInvertido(dest.f+2,dest.c-1,caminos,camino);
		}
	}

}

void muestraTablero(vector <Casilla> camino){
	vector <vector <string> > tablero(8, vector <string> (8));

	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			tablero[i][j]=" ";
		}
	}

	for(int i=0; i<camino.size();i++){
		tablero[camino[i].f-1][camino[i].c-1]="x";
	}

	for(int i=7; i>=0; i--){
		cout<<"\t";
		for(int j=0; j<8; j++){
			cout<<"["<<tablero[i][j]<<"]";
		}
		cout<<endl;
	}
	cout<<"________________________________________________________________"<<endl;

}
