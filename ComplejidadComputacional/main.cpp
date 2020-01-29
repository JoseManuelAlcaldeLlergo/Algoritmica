#include <iostream>
#include "funciones.hpp"


using namespace std;

void opcionQuicksort();
void opcionProductoMatrices();


int main()
{
	int opt=0;
	do{
		cout<<"MENU:\n\t1-Quicksort\n\t2-Producto de matrices\n\t3-Producto de Matrices Strassen\n\t4-Salir"<<endl;
		cin>>opt;
		switch(opt){
			case 1:
		    	opcionQuicksort();
		    	break;
		     case 2:
		     	opcionProductoMatrices();
		     	break;
		     case 3:
		     	opcionStrassen();
		     	break;
		     case 4:
		     	cout<<"FIN DE PROGRAMA"<<endl;
		     	break;
		     default:
		     	cout<<"Opcion no valida"<<endl;
		     	break;
		}
	}while(opt!=4);

}
