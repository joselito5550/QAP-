/**
 * QAPSimpleBestImprovementNO.cpp
 *
 * Fichero que define las funciones de la clase QAPSimpleBestImprovementNO. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPSimpleBestImprovementNO.h"
#include "QAPInstance.h"
#include "QAPSolution.h"
#include "QAPObjectAssignmentOperation.h"
#include "QAPEvaluator.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

bool QAPSimpleBestImprovementNO::findOperation(QAPInstance& instance,
		QAPSolution& solution, QAPChangeOperation& operation) {

	QAPObjectAssignmentOperation *oaOperation = dynamic_cast<QAPObjectAssignmentOperation*>(&operation);
	if (oaOperation == NULL){
		cerr << "QAPSimpleBestImprovementNO::findOperation recibió un objeto operation que no es de la clase QAPObjectAssignmentOperation" << endl;
		exit(1);
	}

	//Crear una permutación de los índices de los objetos e inicializar algunas variables
	vector<int> perm;
	int numLocations = instance.getNumLocations();
	QAPInstance::randomPermutation(numLocations, perm);

	bool initialised = false;
	double bestDeltaFitness = 0;

	/*
	 * 1. Para todo objeto del problema (accediendo en el orden indicado en perm)
	 *   a. Para toda mochila del problema
	 *     i. Obtener el deltaFitness de asignar dicho objeto a dicha mochila en solution
	 *
	 *     ii. Si el deltaFitness es mejor que bestDeltaFitness o si no se había inicializado bestDeltaFitness (initialised == false)
	 *       . Poner initialised a true
	 *       . actualizar bestDeltaFitness
	 *       . actualizar los valores de la operación en oaOperation
	 *
	 * 2. Finalmente, devolver true si bestDeltaFitness es positivo y falso en otro caso
	 *
	 */

	for (int i = 0; i < numLocations; i++){

		for (int j = 0; j < numLocations; j++){
			double deltaFitness = QAPEvaluator::computeDeltaFitness(instance, solution, perm[i], j);

			if (deltaFitness < bestDeltaFitness || initialised == false){
				initialised = true;
				bestDeltaFitness = deltaFitness;
				oaOperation->setValues(perm[i], j, deltaFitness);
			}
		}
	}

	if (bestDeltaFitness < 0)
		return true;
	else
		return false;
}
