#include "funciones_main.hpp"
#include "algorithm.hpp"
#include "suppressioncollinearpointsmethod.hpp"
#include <iostream>
#include "greedymethod.hpp"

void opcion1(){
	//It creates a pointer to algorithm class to use overload in execution
   /* esto sirve para usar un apply u otro segun la herencia de algoritmo que usemos. Por ejemplo:
    a = new CollinearSuppressionMethod(fileNameDC);
   a->apply();
   */  
   Algorithm *a;

   char fileNameDC[100], fileNamePA[100];
   int n;
   cout << "Digital curve to obtain polygonal approximation: ";
   cin >> fileNameDC;

   //Creates a new class for method and the pointer points to the new class
   a = new CollinearSuppressionMethod(fileNameDC);

   //Execute the method
   a->apply();

   cout << "Number of points of the polygonal approxmation: " << a->getNumberPointsPolygonalApproximation() << endl;
   cout << "The value of ISE is " << a->getISE() << endl;

   DigitalCurve aP = a->getPolygonalApproximation();

   cout << "Name of file to save the polygonal approximation: ";
   cin >> fileNamePA;
   
   aP.saveDigitalCurve(fileNamePA);
}

void opcion2(){
   char fileNameDC[100], fileNamePA[100];
   int n;
   Algorithm *a;
   cout << "Curva para obtener la aproximacion poligonal: ";
   cin >> fileNameDC;
   cout<<"Numero de puntos de la aproximacion: ";
   cin>>n;

   //No hace falta distinguir entre abierta o cerrada porque si es cerrada ya se encarga calculatePolygonalApproximation() de añadir el punto que falta
   a = new GreedyMethod(fileNameDC,n);

   a->apply();

   //Valor del ISE con la parte opcional incluida
   cout << "El valor del ISE final es " << a->getISE() << endl;   

   DigitalCurve aP = a->getPolygonalApproximation();

   cout << "Introduzca el nombre del archivo para guardar la aproximacion: ";
   cin >> fileNamePA;
   
   //Para comprobar nuestra aproximacion la guardamos en un nuevo fichero
   aP.saveDigitalCurve(fileNamePA);
}