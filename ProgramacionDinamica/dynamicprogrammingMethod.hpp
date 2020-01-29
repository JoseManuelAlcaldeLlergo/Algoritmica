#ifndef DINAMICPROGRAMMINGMETHOD_HPP
#define DINAMICPROGRAMMINGMETHOD_HPP

#include "algorithm.hpp"
#include <vector> 

//This class implements a method for obtaining a polygonal approximation
class DynamicProgrammingMethod:public Algorithm
{
	private:


	public:
		DynamicProgrammingMethod(char * fileName, int n);
		~DynamicProgrammingMethod();
		//Inherited method from algorithm class. It must be implemented in all inherited classes
		//This method calculates the polygonal approximation
		void apply();
		
};
		

#endif