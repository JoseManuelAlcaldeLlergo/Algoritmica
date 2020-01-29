#include "algorithm.hpp"
#include "suppressioncollinearpointsmethod.hpp"
#include "funciones_main.hpp"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
   
   int opt=0;

   do{   
      cout<<"MENU:\n\t1-Eliminación de puntos colineales\n\t2-Método greedy\n\t3-Salir"<<endl;
      cout<<"Introduzca la opcion deseada: ";
      cin>>opt;

      switch(opt){
         case 1:
            opcion1();
            break;
         case 2:
            opcion2();
            break;
         case 3:
            cout<<"FIN DEL PROGRAMA"<<endl;
            break;
         default:
            cout<<"Opción no válida"<<endl;
            break;
      }
   }while(opt!=3);


   
   return 0;
}
