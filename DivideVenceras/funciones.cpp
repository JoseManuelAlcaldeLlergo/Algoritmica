#include "funciones.hpp"
#include <iostream>
#include "entero.hpp"

using namespace std;


void opcion1(){

	Entero a;
	Entero b;

	cout<<"Opcion: SUMA"<<endl<<endl;
	cout<<"Introduzca el primer sumando: ";
	cin>>a;
	cout<<"Introduzca el segundo sumando: ";
	cin>>b;

	
	cout<<a<<"+"<<b<<"="<<a+b<<endl;
}

void opcion2(){

	Entero a;
	Entero b;

	cout<<"Opcion: PRODUCTO"<<endl<<endl;
	cout<<"Introduzca el primer operando: ";
	cin>>a;
	cout<<"Introduzca el segundo operando: ";
	cin>>b;


	cout<<a<<"*"<<b<<"="<<a*b<<endl;
}

void opcion3(){

	Entero a,f;

	cout<<"Opcion: FACTORIAL"<<endl<<endl;
	cout<<"Introduzca el numero al que va a realizar el factorial: ";
	cin>>a;
	
	f.setN(Factorial(a).getN());
	cout<<a<<"!= "<<f<<endl;
}

