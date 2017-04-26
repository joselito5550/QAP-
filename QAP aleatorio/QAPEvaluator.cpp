/*
 * QAPEvaluator.cpp
 *
 * Fichero que define los métodos de la clase QAPEvaluator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPEvaluator.h"
#include "QAPSolution.h"
#include "QAPInstance.h"


double QAPEvaluator::computeFitness(QAPInstance &instance, QAPSolution &solution){

	double fitness = 0;

	fitness = instance.getSumCost(solution);
	
	return fitness;
}
