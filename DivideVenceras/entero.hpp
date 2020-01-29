#ifndef ENTERO_H
#define ENTERO_H

#include <iostream>

using namespace std;

class Entero{

private:
	string n_;
	int max_;

public:
	Entero();

	Entero(int n);

	Entero(string n);
	
	inline string getN(){return n_;}
	inline void setN(string s){n_=s;}

	inline int getMaximo(){return max_;}

	void partirCadena(Entero &s1, Entero &s2);

	void agregarCerosFinal(int nCeros);

	void agregarCerosDelante(int nCeros);

	void quitarCerosNoSignificativos();

	Entero resta1();

	Entero multiplicarPotencia10(int potencia);

	Entero & operator=(Entero &m);

	Entero & operator=(int &m);


};

Entero & operator+(Entero a, Entero b);

Entero & operator*(Entero a, Entero b);

ostream &operator<<(ostream &stream, Entero &m);

istream &operator>>(istream &stream, Entero &m);

Entero Factorial(Entero a);


#endif