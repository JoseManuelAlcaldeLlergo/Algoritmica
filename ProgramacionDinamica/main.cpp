#include "algorithm.hpp"
#include "funciones_menu.hpp"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{   
  int opt=0;

do{   
   cout<<"MENU:\n\t1-Eliminación de puntos colineales\n\t2-Método dinámico\n\t3-Salir"<<endl;
   cout<<"Introduzca la opción deseada: ";
   cin>>opt;

   switch(opt){
      case 1:
         suppressionColinear();
         break;
      case 2:
         dynamic();
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
