#include "funciones_menu.hpp"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{   
  int opt=0;

do{   
   cout<<"--------------------------------------------------------------------------------"<<endl;
   cout<<"MENU:\n\n\t1-N-Reinas Backtracking\n\n\t2-N-Reinas las Vegas\n\n\t3-Calculo de tiempos Backtracking\n\n\t4-Comparar Bactracking y las Vegas para N-Reinas\n\t (Poner terminal en pantalla completa para ver bien la tabla)\n\n\t5-Salir\n"<<endl;
   cout<<"Introduzca la opción deseada: ";
   cin>>opt;
   cout<<"--------------------------------------------------------------------------------"<<endl;

   switch(opt){
      case 1:
         opc_Backtracking();
         break;
      case 2:
         opc_Probabilista();
         break;
      case 3:
         opc_calculaTiemposReinasBacktracking();
         break;
      case 4:
         opc_comparaAlgoritmosReinas();
         break;
      case 5:
         cout<<"FIN DEL PROGRAMA"<<endl;
         break;
      default:
         cout<<"Opción no válida"<<endl;
         break;
   }
}while(opt!=5);



return 0;
}
