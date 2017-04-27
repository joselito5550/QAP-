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
#include "stdlib.h"
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
	int numFacilities = instance.getNumLocations();
	QAPInstance::randomPermutation(numFacilities, perm);
	//int numKnapsacks = instance.getNumObjs();
	bool initialised = false;
	double bestDeltaFitness = 0;
	double deltaFitness;
	/* TODO
	 * 1. Para todo objeto del problema (accediendo en el orden indicado en perm)
	 *   a. Para toda mochila del problema (Nota: no te olvides de ninguna)
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

	for (int i=0; i<numFacilities; i++)
	{
		for (int j=i+1; j<numFacilities; j++)
		{
			//cout << i << " " << j << endl;
			deltaFitness = QAPEvaluator::computeDeltaFitness(instance, solution, i,j); 
			//deltaFitness=instance.getDeltaSumProfits(solution, perm[i], j);
			if (initialised == false)
			{
				bestDeltaFitness=deltaFitness;
				initialised=true;
				oaOperation->setValues(i,j,deltaFitness);
				//oaOperation.apply(solution);	/*No lo tengo claro*/
			}
			if (deltaFitness > bestDeltaFitness)
			{
				bestDeltaFitness=deltaFitness;
				oaOperation->setValues(i,j,deltaFitness);
				//oaOperation.apply(solution);	/*No lo tengo claro*/
			}
		}
	}
	if (bestDeltaFitness > 0)
		return false;
	else{
		return true;
	
	}
}
