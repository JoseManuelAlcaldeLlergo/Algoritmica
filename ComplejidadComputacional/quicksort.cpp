#include <iostream>
#include <vector>
#include <ctime>
#include "quicksort.hpp"
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include "funciones.hpp"

using namespace std;




// Función para dividir el array y hacer los intercambios
int divide(vector<double> &v, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
 
    pivot = v[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (v[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (v[left] <= pivot)) {
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = v[left];
            v[left] = v[right];
            v[right] = temp;
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = v[right];
    v[right] = v[start];
    v[start] = temp;
 
    // La nueva posición del pivot
    return right;
}
 
// Función recursiva para hacer el ordenamiento
void quicksort(vector<double> &v, int start, int end)
{
    int pivot;
 
    if (start < end) {
        pivot = divide(v, start, end);
 
        // Ordeno la lista de los menores
        quicksort(v, start, pivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(v, pivot + 1, end);
    }
}

void rellenarVector(vector<double> &v){

    srand(time(NULL));
    for(unsigned int i=0; i<v.size();i++){
        v[i]=rand()%10000;
        //cout<<v[i]<<" ";
    }

}

void estaOrdenado(const vector <double> &v)
{
    for(int i=0; i<v.size()-1; i++){
        assert(v[i]<=v[i+1]);
    }
}



