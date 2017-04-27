/*
 * QAPSimpleFirstImprovementNO.cpp
 *
 * Fichero que define las funciones de la clase QAPSimpleFirstImprovementNO.Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPSimpleFirstImprovementNO.h"
#include "QAPInstance.h"
#include "QAPEvaluator.h"
#include "QAPObjectAssignmentOperation.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


// Revisar 
bool QAPSimpleFirstImprovementNO::findOperation(QAPInstance &instance, QAPSolution &solution, QAPChangeOperation &operation) {

	QAPObjectAssignmentOperation *oaOperation = dynamic_cast<QAPObjectAssignmentOperation*>(&operation);
	if (oaOperation == NULL){
		cerr << "QAPSimpleFirstImprovementNO::findOperation recibió un objeto operation que no es de la clase QAPObjectAssignmentOperation" << endl;
		exit(1);
	}

	//Crear una permutación de los índices de los objetos e inicializar algunas variables
	vector<int> perm;
	int numLocations = instance.getNumLocations();
	QAPInstance::randomPermutation(numLocations, perm);

	/* TODO
	 * 1. Para todo objeto del problema (accediendo en el orden indicado en perm)
	 *   a. Para toda mochila del problema (Nota: no te olvides de ninguna)
	 *     i. Obtener el deltaFitness de asignar dicho objeto a dicha mochila en solution
	 *
	 *     ii. Si el deltaFitness es positivo
	 *       . actualizar los valores de la operación en oaOperation
	 *       . Salir devolviendo true
	 *
	 * 2. Si se llega a este punto, no se encontró ningún deltaPositivo y se devuelve false
	 *
	 */
	for(int i=0; i < numLocations; i++){
		int indexFacility = perm[i];

		for(int j=0; j <= numLocations; j++){
			double deltaFitnessCurrent = QAPEvaluator::computeDeltaFitness(instance, solution, indexFacility,j); 

			if(deltaFitnessCurrent < 0)
			{				
				oaOperation->setValues(indexFacility,j,deltaFitnessCurrent);				
				return true;
			}

		}

	}
	return false;
}



