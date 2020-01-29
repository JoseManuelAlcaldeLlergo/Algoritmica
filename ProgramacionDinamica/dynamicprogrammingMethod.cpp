
#include <vector>    // necesario para el contenedor vector
#include "algorithm.hpp"
#include "dynamicprogrammingMethod.hpp"
#include "digitalcurve.hpp"
#include "point.hpp"


using namespace std;

/* Functions for Collinear suppression method */

//Constructor.

DynamicProgrammingMethod::DynamicProgrammingMethod(char *fileName,int n)
{
  //A digital curve is created to load the digital curve in file
	DigitalCurve dc(fileName);
  
  //Digital curve as saved as original curve
  setOriginalCurve(dc);

  setNumberPointsPolygonalApproximation(n);
}

//Destructor
DynamicProgrammingMethod::~DynamicProgrammingMethod()
{
}

void DynamicProgrammingMethod::apply()
{

  //Summations are calculated
	calculateSummations();

	int M=getNumberPointsPolygonalApproximation();
	int N=getOriginalCurve().getNumberPointsDigitalCurve();
	vector <vector <int> > padres(N, vector <int> (M));
	vector <vector <double> > E(N, vector <double> (M));
	long double menor = 999999999999.;
	long double res;
	int pospadre;
	vector <Point> points;
	vector <int> dominantes;


	//Casos base
	E[0][0]=0;
	for(int i=1; i<N;i++){
		E[i][0]=999999999999.;
	}


	for(int m=1; m<M; m++){
		for(int n=m; n<N; n++){
			for(int k=m-1; k<n; k++){
				res=E[k][m-1]+calculateISEValue(k,n); 
				if(menor>res){
					menor=res;
					pospadre=k;
				}
			}

			E[n][m]=menor;
			padres[n][m]=pospadre;

			menor=999999999999.;
		}
	}

	//Mostrar todos los padres
	/*cout<<"Matriz padres: "<<endl;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<"padre["<<i<<"]["<<j<<"]= "<<padres[i][j]<<endl;
		}
	}*/

	//El último padre es el primer dominante, a partir de él vamos sacando los demás
	dominantes.push_back(pospadre);

	for(int i=M-1; i>0; i--){
		dominantes.push_back(padres[pospadre-1][i])	;
		pospadre=padres[pospadre-1][i];
	}

	//Como hemos insertado los padres en orden inverso, le damos la vuelta al vector
	reverse(dominantes.begin(),dominantes.end());

	//Mostrar los dominantes de la aproximación
	for(int i=0; i<dominantes.size();i++){
		cout<<"dominante["<<i<<"]= "<<dominantes[i]<<endl;;
	}

	cout<<"El error sacado de la matriz es: "<<E[N-1][M-1]<<endl;

	setDominantPointsPosition(dominantes);

	//Obtaining polygonal approximattion
	calculatePolygonalApproximation();

	//Set the number of points of the polygonal approximation
	setNumberPointsPolygonalApproximation(getPolygonalApproximation().getNumberPointsDigitalCurve());

}