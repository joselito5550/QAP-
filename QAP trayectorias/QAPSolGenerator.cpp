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

void QAPSolGenerator::genRandomSol(QAPInstance &instance, QAPSolution &solution){

	int numLocation = instance.getNumLocations();
	vector<Randomhelp> aux;

	vector<int> perm;
	QAPInstance::randomPermutation(numLocation, perm);
	for(int i=0; i<numLocation; i++)
	{
		solution.putFacility(i,perm[i]);
	}

}

