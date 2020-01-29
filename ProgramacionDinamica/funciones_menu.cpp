#include "funciones_menu.hpp"
#include "suppressioncollinearpointsmethod.hpp"
#include "dynamicprogrammingMethod.hpp"

void suppressionColinear(){
	//It creates a pointer to algorithm class to use overload in execution
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

void dynamic(){
   char fileNameDC[100], fileNamePA[100];
   int m;
   Algorithm *a;
   cout << "Curva para obtener la aproximacion poligonal: ";
   cin >> fileNameDC;
   cout<<"Numero de puntos de la aproximacion: ";
   cin>>m;

   a = new DynamicProgrammingMethod(fileNameDC,m);

   //Execute the method
   a->apply();

   cout << "El valor del ISE es: " << a->getISE() << endl;

   DigitalCurve aP = a->getPolygonalApproximation();

   cout << "Nombre del archivo para guardar la aproximación: ";
   cin >> fileNamePA;
   
   aP.saveDigitalCurve(fileNamePA);
}