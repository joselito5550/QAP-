/*
 * QAPObjectAssignmentOperation.cpp
 *
 * Fichero que define las funciones de la clase QAPObjectAssignmentOperation. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPObjectAssignmentOperation.h"


QAPObjectAssignmentOperation::QAPObjectAssignmentOperation(){
	_indexLoc1 = 0;
	_indexLoc2 = 0;
	_deltaFitness = 0;
}

QAPObjectAssignmentOperation::~QAPObjectAssignmentOperation() {
}

void QAPObjectAssignmentOperation::apply(QAPSolution& solution) {

	double sumFitness = 0;

	solution.intercambio(_indexLoc1, _indexLoc2);

	sumFitness = _deltaFitness + solution.getFitness();

	solution.setFitness(sumFitness);
}

void QAPObjectAssignmentOperation::setValues(int indexLoc1, int indexLoc2, double deltaFitness) {

	 	this->_indexLoc1 = indexLoc1;
		this->_indexLoc2 = indexLoc2;
		this->_deltaFitness = deltaFitness;
}