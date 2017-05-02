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

	int numObjs = instance.getNumObjs();
	int numKnapsacks = instance.getNumKnapsacks();

	for (int i = 0; i < numObjs; i++){
		int randomKnapsack = rand() % (numKnapsacks + 1);
		solution.putObjectIn(i, randomKnapsack);
	}
}

