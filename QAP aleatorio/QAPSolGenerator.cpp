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


void QAPSolGenerator::genRandomSol(QAPInstance &instance, QAPSolution &solution){

	int numLocation = instance.getNumLocations();
	vector<Randomhelp> aux;

	for(int i = 0; i< numLocation; i++){
		Randomhelp help;
		help.num = i;
		aux.push_back(help);
	}

	//Aqui recorremos las localizaciones
	for (int i = 0; i < numLocation; i++){

		int num = 1 + rand() % (101-1);

		int randomLocation = rand()%(numLocation); 

		if(aux[randomLocation].used == false)
		{
			solution.putFacility(i, randomLocation);
			aux[randomLocation].used = true;
		}
		else 
		i--;
	}
	



}
