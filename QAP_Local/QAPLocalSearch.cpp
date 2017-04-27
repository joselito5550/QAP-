/*
 * QAPLocalSearch.cpp
 *
 * Fichero que define las funciones de la clase QAPLocalSearch. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPLocalSearch.h"
#include "QAPInstance.h"
#include "QAPSolution.h"
#include "QAPNeighExplorer.h"
#include "QAPObjectAssignmentOperation.h"
#include <iostream>

QAPLocalSearch::QAPLocalSearch() {
}

QAPLocalSearch::~QAPLocalSearch() {
}

void QAPLocalSearch::optimise(QAPInstance& instance, QAPNeighExplorer& explorer, QAPSolution& solution) {

	_results.clear();
	_results.push_back(solution.getFitness());
	QAPObjectAssignmentOperation operation;

	/** 
	 * 1. Aplica una vez la exploración del vecindario y almacena si se ha conseguido o no mejorar la solución
	 *
	 * 2. Mientras se haya conseguido mejorar la solución
	 *   a. Aplica el cambio indicado en la exploración anterior
	 *   b. Almacena en _results el nuevo fitness de la solución
	 *   c. Aplica una nueva exploración del vecindario
	 */



	while (explorer.findOperation(instance, solution, operation)==true)
	{
		operation.apply(solution);
		_results.push_back(solution.getFitness());
	}

}
