/*
269-->(8,7)
205-->(8,8)*/


#include <iostream>
#include "funciones.hpp"
#include "opciones.hpp"

using namespace std;


int main(){

	int opt=0;

	do{
		cout<<"\nMENU:\n\t1-Calculo de los caminos posibles para llegar desde cualquier casilla de la fila 1 a cualquiera de la fila 8"<<endl;
		cout<<"\n\t2-Calculo de los caminos posibles para llegar a la fila 8 desde la casilla (1,2)"<<endl;
		cout<<"\n\t3-Calculo de los caminos posibles para llegar a la fila 8 desde la casilla (1,7)"<<endl;
		cout<<"\n\t4-Salir"<<endl;
		cout<<"\nIntroduzca la opcion deseada: ";

		cin>>opt;
		switch(opt){
			case 1:
				opcion1(); 
				break;
			case 2:
				opcion2();
				break;
			case 3:
				opcion3(); 
				break;
			case 4:
				break;
			default:
				cout<<"Opción no válida"<<endl;
				break;
		}
	}while(opt!=4);
}
