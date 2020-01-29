#include "funciones_probabilistas.hpp"
#include <vector>
#include <cstdlib>
#include <iostream>

#include "funciones_reinas.hpp" 


using namespace std;


void nReinasLasVegas(int nreinas, vector <int> &posiciones, bool &exito){

	posiciones.resize(nreinas+1);	//el +1 es para solucionar el indexado
	vector <int> ok (nreinas+1,0);
	int cont=0;
	int col;
	

	for(int i=1; i<=nreinas; i++){
		posiciones[i]=0;
	}

	for(int k=1; k<=nreinas; k++){
		cont=0;
		for(int j=1; j<=nreinas;j++){
			posiciones[k]=j;
			if(posibleLugar(k,posiciones)==true){
				cont++;
				ok[cont]=j;
			}
		}
		if(cont==0){break;}
		
		col=ok[1+rand()%cont];
		posiciones[k]=col;

	}
	
	if(cont==0){
		exito=false;
	}
	else{
		exito=true;
	}

}