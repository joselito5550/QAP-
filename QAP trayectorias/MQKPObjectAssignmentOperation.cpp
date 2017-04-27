/*
 * MQKPObjectAssignmentOperation.cpp
 *
 * Fichero que define las funciones de la clase MQKPObjectAssignmentOperation. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "MQKPObjectAssignmentOperation.h"

MQKPObjectAssignmentOperation::MQKPObjectAssignmentOperation(){
	_indexFacility1 = 0;
	_indexFacility2 = 0;
	_deltaFitness = 0;
}

MQKPObjectAssignmentOperation::~MQKPObjectAssignmentOperation() {
}

void MQKPObjectAssignmentOperation::apply(MQKPSolution& solution) {
	/*
	 * 1. Asigna el objeto de índice _indexObj a la mochila _indexKnapsack en solution
	 * 2. Actualiza el fitness de solution sumándole _deltaFitness
	 */
	
	int location1 = solution.whereIsFacility(_indexFacility1);
	int location2 = solution.whereIsFacility(_indexFacility2);


	solution.putFacility(_indexFacility1, location2);
	solution.putFacility(_indexFacility2, location1);

	double suma_fitness = 0;
	suma_fitness=_deltaFitness + solution.getFitness();
	solution.setFitness(suma_fitness);
}

void MQKPObjectAssignmentOperation::setValues(int indexObject,
		int indexKnapsack, double deltaFitness) {
	/*
	 * Guarda los valores pasados como argumentos en las variables miembro
	 */
	_indexKnapsack = indexKnapsack;
	_indexObj = indexObject;
	_deltaFitness = deltaFitness;
}
