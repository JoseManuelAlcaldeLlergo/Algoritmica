
#include <vector>    // necesario para el contenedor vector
#include "algorithm.hpp"
#include "greedymethod.hpp"
#include "digitalcurve.hpp"
//#include "heapvectorMasood.hpp"
//#include "nodoMasood.hpp"



using namespace std;

/* Functions for Collinear suppression method */

//Constructor.

GreedyMethod::GreedyMethod(char *fileName, int numberPointsPolygonalApproximation)
{
  //A digital curve is created to load the digital curve in file
	DigitalCurve dc(fileName);
  
  //Digital curve as saved as original curve
  setOriginalCurve(dc);

  //Set the number of points of the polygonal approximation
  setNumberPointsPolygonalApproximation(numberPointsPolygonalApproximation);
}

//Destructor
GreedyMethod::~GreedyMethod()
{
}

void GreedyMethod::apply()
{
	//Calculamos los sumatorios
	calculateSummations();

	//Eliminamos los puntos colineales
	collinearPointsElimination();

	//Incremento que debemos usar para coger el numero de puntos deseado para nuestra aproximacion
	int incr=getDominantPointsPosition().size()/(getNumberPointsPolygonalApproximation()-1);

	vector<int> new_points;

	double error=0.;
	double error2=0.;
	long double ISE=0;

	//Utilizamos el incremento para obtener los primeros candidatos de la aproximacion
	for(int i=0; i<getDominantPointsPosition().size(); i+=incr){
		new_points.push_back(getDominantPointsPosition()[i]);
	}

	//Nos aseguramos de coger el ultimo punto
	if(getDominantPointsPosition()[getDominantPointsPosition().size()-1]!=new_points[new_points.size()-1]){
		new_points.erase(new_points.end()-1);
		new_points.push_back(getDominantPointsPosition()[getDominantPointsPosition().size()-1]);
	}

	//Hay casos que con ese incremento coge puntos de mas, asi que me aseguro de dejar un numero de puntos equivalente al deseado quitando los penultimos
	while(new_points.size()>getNumberPointsPolygonalApproximation()){
		new_points.erase(new_points.end()-2);
	}

	setDominantPointsPosition(new_points);

	do{
		//Guardo el ISE actual para ver si se reduce
		ISE=getISE();
		
		for(int i=1; i<new_points.size(); i++){
			if(i==new_points.size()-1){			//Si es el ultimo punto, debo calcular el error respecto al penultimo y el dominante 1
				error=calculateISEValue(new_points[i-1],new_points[i])+calculateISEValue(new_points[i],new_points[1]);
				for(int j=new_points[0]; j<new_points[1];j++){
					error2=calculateISEValue(new_points[0],j)+calculateISEValue(j,new_points[1]);
					if(error2<error){
						error=error2;
						new_points[i]=j;
					}
				}
			}
			else{								//Si no es el ultimo, el error es entre el de antes y el de despues
				error=calculateISEValue(new_points[i-1],new_points[i])+calculateISEValue(new_points[i],new_points[(i+1)]);
				for(int j=new_points[i-1]; j<new_points[i+1];j++){
					error2=calculateISEValue(new_points[i-1],j)+calculateISEValue(j,new_points[(i+1)]);
					if(error2<error){
						error=error2;
						new_points[i]=j;
					}
				}

			}
		}

		//Asignamos los nuevos puntos dominantes
		setDominantPointsPosition(new_points);
	}while(getISE()!=ISE);


	//Asignamos la nueva aproximacion, y en caso de que sea cerrada añade un punto mas
	calculatePolygonalApproximation();

	//Asignamos el numero de puntos de la aproximacion poligonal
	setNumberPointsPolygonalApproximation(getPolygonalApproximation().getNumberPointsDigitalCurve());

}

