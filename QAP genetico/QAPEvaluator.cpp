/*
 * QAPEvaluator.cpp
 *
 * Fichero que define los métodos de la clase QAPEvaluator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPEvaluator.h"
#include "QAPInstance.h"
#include "QAPSolution.h"

unsigned QAPEvaluator::_numEvaluations = 0;

double QAPEvaluator::computeFitness(QAPInstance &instance, QAPSolution &solution){

	double fitness = 0;

	fitness=instance.getSumCoste(solution);
	 
	 _numEvaluations++;
	
	return fitness;
}

double QAPEvaluator::computeDeltaFitness(QAPInstance& instance, QAPSolution& solution, int loc1, int loc2) {

	double fitness = 0;

	fitness = instance.getDeltaSumCoste(solution,loc1,loc2);

	_numEvaluations++;

	return fitness;
}

void QAPEvaluator::resetNumEvaluations() {
	_numEvaluations = 0;
}

