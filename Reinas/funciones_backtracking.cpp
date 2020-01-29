#include "funciones_backtracking.hpp"
#include "funciones_reinas.hpp"
#include <vector>


using namespace std;

void nReinasBacktracking(int nreinas,vector <vector <int> > &soluciones,bool unaSolucion){
	vector <int> posiciones (nreinas+1,0);	//el +1 es para solucionar el indexado
	int fila=1;

	posiciones[1]=0;
	while(fila>0){
		posiciones[fila]=posiciones[fila]+1;
		while(posiciones[fila]<=nreinas && posibleLugar(fila,posiciones)==false){
			posiciones[fila]=posiciones[fila]+1;
		}
		if(posiciones[fila]<=nreinas){
			if(fila==nreinas){
				soluciones.push_back(posiciones);
				if(unaSolucion){fila=-1;}
			}
			else{
				fila=fila+1;
				posiciones[fila]=0;
			}
		}
		else{
			fila=fila-1;
		}
	}
}

