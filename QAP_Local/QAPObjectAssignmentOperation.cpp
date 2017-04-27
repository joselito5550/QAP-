/*
 * QAPObjectAssignmentOperation.cpp
 *
 * Fichero que define las funciones de la clase QAPObjectAssignmentOperation. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPObjectAssignmentOperation.h"

QAPObjectAssignmentOperation::QAPObjectAssignmentOperation(){
	//_indexLocation1 = 0;
	//_indexLocation2 = 0;
	_indexFacility1 = 0;
	_indexFacility2 = 0;
	_deltaFitness = 0;
}

QAPObjectAssignmentOperation::~QAPObjectAssignmentOperation() {
}

void QAPObjectAssignmentOperation::apply(QAPSolution& solution) {
	/* TODO
	 * 1. Asigna el objeto de índice _indexObj a la mochila _indexKnapsack en solution
	 * 2. Actualiza el fitness de solution sumándole _deltaFitness
	 */
	//int loc1 = solution.whereIsObject(_indexLocation1);
	//int loc2 = solution.whereIsObject(_indexLocation2);
	//solution.putObjectIn(_indexLocation1,loc2); //Permutación de 2 edificios
	//solution.putObjectIn(_indexLocation2,loc1);
	//De esta manera quedarían permutadas las posiciones

	int location1 = solution.whereIsFacility(_indexFacility1);
	int location2 = solution.whereIsFacility(_indexFacility2);


	solution.putFacility(_indexFacility1, location2);
	solution.putFacility(_indexFacility2, location1);

	double suma_fitness = 0;
	suma_fitness=_deltaFitness + solution.getFitness();
	solution.setFitness(suma_fitness);
}

void QAPObjectAssignmentOperation::setValues(int indexFacility1, int indexFacility2, double deltaFitness) {
	/* TODO
	 * Guarda los valores pasados como argumentos en las variables miembro
	 */
	//_indexLocation1 = indexLocation1;
	//_indexLocation2 = indexLocation2;
	_indexFacility1 = indexFacility1;
	_indexFacility2 = indexFacility2;
	_deltaFitness = deltaFitness;
}
