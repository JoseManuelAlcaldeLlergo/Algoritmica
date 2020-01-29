#include "funciones_reinas.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;


bool posibleLugar(int fila, vector <int> posiciones){
	
	for(int i=1; i<=fila-1;i++){
		if(posiciones[i]==posiciones[fila] || abs(posiciones[i]-posiciones[fila])==abs(i-fila)){
			return false;
		}
	}
	return true;
}

void muestraTablero(vector <int> posiciones,int n){
	vector <vector <string> > tablero(n, vector <string> (n));

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			tablero[i][j]=" ";
		}
	}

	cout<<endl;
	for(int i=1; i<posiciones.size();i++){
		tablero[i-1][posiciones[i]-1]="x";
	}

	for(int i=n-1; i>=0; i--){
		cout<<"\t";
		for(int j=0; j<n; j++){
			cout<<"["<<tablero[i][j]<<"]";
		}
		cout<<endl;
	}
	cout<<"________________________________________________________________"<<endl;

}