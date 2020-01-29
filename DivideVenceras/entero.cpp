#include "entero.hpp"
#include <iostream>
#include <vector>

using namespace std;

Entero::Entero(){
	this->max_=4;
	this->setN("0");
}

Entero::Entero(int n){
	this->max_=4;
	this->setN(to_string(n));
}

Entero::Entero(string n){
	this->max_=4;
	this->setN(n);
}

void Entero::partirCadena(Entero &s1, Entero &s2){


	if(this->getN().size()%2!=0){
		this->agregarCerosDelante(1);
	}

	int s=this->getN().size()/2;

	s1.setN(this->getN().substr(0,s));
	s2.setN(this->getN().substr(s,this->getN().size()));
}

void Entero::agregarCerosFinal(int nCeros)
{
	for(int i=0; i<nCeros; i++){
		this->setN(this->getN()+"0");
	}
}

void Entero::agregarCerosDelante(int nCeros)
{
	for(int i=0; i<nCeros; i++){
		this->setN("0"+this->getN());
	}
}

void Entero::quitarCerosNoSignificativos()
{
	while(this->getN()[0]=='0'){
		n_.erase(0,1);
	}
}

Entero Entero::multiplicarPotencia10(int potencia)
{
	this->agregarCerosFinal(potencia);
	return *this;

}


Entero & Entero::operator=(Entero &m)
{
	this->setN(m.getN());

	// Se devuelve el objeto actual
	return *this;
}

Entero & Entero::operator=(int &m)
{
	this->setN(to_string(m));

	// Se devuelve el objeto actual
	return *this;
}

Entero & operator+ (Entero a, Entero b)
{
	if(a.getN().size()<b.getN().size()){
			
		a.agregarCerosDelante(b.getN().size()-a.getN().size());		
	}
	else if(a.getN().size()>b.getN().size()){
		b.agregarCerosDelante(a.getN().size()-b.getN().size());	
	}

	// Se crea un nuevo objeto
	Entero *nuevo = new Entero();

	
	int aux;
	string n="";
	string retorno;
	int resto=0;
	//vector <int> x,y
	int x, y;
	
	for(int i=a.getN().size()-1;i>=0;i--){
		x=a.getN()[i]-'0';
		y=b.getN()[i]-'0';
		aux=x+y+resto;
		//cout<<"x= "<<x<<" y="<<y<<" aux= "<<aux<<endl;
		if (aux < 10)
		{
			n = '0' + aux;
			retorno=n+retorno;
			//cout<<a.getN()[i]<<"+"<<b.getN()[i]<<"= "<<n<<endl;
			resto=0;
		}
		else
		{
				n = '0' + aux%10;
				retorno=n+retorno;
				resto=1;
		}

	}
	if(resto==1){
			retorno="1"+retorno;
		}
	nuevo->setN(retorno);

	nuevo->quitarCerosNoSignificativos();
	
	// Se devuelve el resultado
	return *nuevo;
}


Entero & operator*(Entero a, Entero b){

	Entero w, x, y, z, p, q, xy, wz;
	int n, s;
	Entero *nuevo = new Entero();
	
	//Igualamos el numero de digitos de a y b
	if(a.getN().size()<b.getN().size()){
			
		a.agregarCerosDelante(b.getN().size()-a.getN().size());		
	}
	else if(a.getN().size()>b.getN().size()){
		b.agregarCerosDelante(a.getN().size()-b.getN().size());	
	}


	//hacemos que tengan siempre un numero par de digitos
	if(a.getN().size()%2!=0){
		a.agregarCerosDelante(1);
		b.agregarCerosDelante(1);
	}


	if(a.getN().size()<=a.getMaximo()){
		nuevo->setN(to_string(stoi(a.getN())*stoi(b.getN())));
		return *nuevo;
	}
	else{
		s=a.getN().size()/2;
		a.partirCadena(w,x);
		b.partirCadena(y,z);

		//Realizamos los productos necesarios
		p=w*y;
		q=x*z;
		wz=w*z;
		xy=x*y;

		//Realizamos la potencia de 10 conveniente para cada producto y las sumamos
		nuevo->setN(((p.multiplicarPotencia10(2*s)+(wz+xy).multiplicarPotencia10(s)+q)).getN());
		return *nuevo;

	}

	// Se devuelve el resultado
	return *nuevo;
}

ostream &operator<<(ostream &stream, Entero &m) {
	stream<<m.getN();
	
	m.quitarCerosNoSignificativos();
	
	// Se devuelve el flujo de salida
	return stream;
}

istream &operator>>(istream &stream, Entero &m){

	string s;
	stream>>s;
	
	m.setN(s);

	// Se devuelve el flujo de entrada
	return stream;
}

Entero Factorial(Entero a){

	Entero fact("1");
	Entero incremento1("1");
	Entero cont("1");
	do{
		fact=fact*cont;
		cont=cont+incremento1;
	}while(cont.getN()!=((a+incremento1).getN()));	//Acabo en a+1 porque cont empieza en 1

	return fact;
}