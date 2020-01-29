#include <iostream>
#include "funciones.hpp"


using namespace std;



int main(){

	int opt;

	do{
		cout<<"______________________________________"<<endl;
		cout<<"\tMENU:"<<endl;
		cout<<"\n\t\t1.-SUMA"<<endl;
		cout<<"\t\t2.-PRODUCTO"<<endl;
		cout<<"\t\t3.-FACTORIAL"<<endl;
		cout<<"\t\t4.-SALIR"<<endl;
		cout<<"\nOpcion: ";
		cin>>opt;
		cout<<"______________________________________"<<endl<<endl;

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
				cout<<"FIN DEL PROGRAMA"<<endl;
				break;

			default:
				cout<<"Opcion no valida"<<endl;
		}
	}while(opt!=4);

}


