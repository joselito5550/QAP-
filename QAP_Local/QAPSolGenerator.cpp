/*
 * QAPSolGenerator.cpp
 *
 * Fichero que define los métodos de la clase QAPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPSolGenerator.h"
#include "QAPInstance.h"
#include "QAPSolution.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

 using namespace std;

/*void QAPSolGenerator::genRandomSol(QAPInstance &instance, QAPSolution &solution){

	int numObjs = instance.getNumObjs();
	int numKnapsacks = numObjs;

	for (int i = 0; i < numObjs; i++){
		int randomKnapsack = rand() % (numKnapsacks + 1);
		solution.putObjectIn(i, randomKnapsack);
	}
}*/
void QAPSolGenerator::genRandomSol(QAPInstance &instance, QAPSolution &solution){

	int numLocation = instance.getNumLocations();
	vector<Randomhelp> aux;


	// for(int i = 0; i< numLocation; i++){
	// 	Randomhelp help;
	// 	help.num = i;
	// 	aux.push_back(help);
	// }
	// //Aqui recorremos los edificios
	// for (int i = 0; i < numLocation; i++){
		 

	// 	int randomLocation = rand()%(numLocation);  //TODO Cambiar para seleccionar una de las mochilas disponibles

	// 	if(aux[randomLocation].used == false){
	// 		solution.putFacility(i, randomLocation);
	// 		aux[randomLocation].used = true;
	// 	}
	// 	else 
	// 	i--;
	// }
	vector<int> perm;
	QAPInstance::randomPermutation(numLocation, perm);
	for(int i=0; i<numLocation; i++)
	{
		solution.putFacility(i,perm[i]);
	}



		// for(int i=0; i < 26; i++)
		// {
		// 	cout << perm[i] << " ";
		// 	std::cout << solution.whereIsFacility(i) << " ";
		// }
		// std::cout << std::endl;



}
