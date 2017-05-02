/*
 * QAPSolution.cpp
 *
 * Fichero que define los métodos de la clase QAPSolution. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPSolution.h"
#include "QAPInstance.h"
#include <iostream>

using namespace std;

QAPSolution::QAPSolution(QAPInstance &instance) {
	// inicializando las variables miembro. Inicialmente, todos los objetos estarán fuera de las mochilas ( = 0)
	_numFacilities = instance.getNumObjs();
	_fitness = 0;
	_sol = new int[_numFacilities];
	if (!_sol) {
		cerr << "No se ha reservado memoria correctamente para _sol" << endl;
		exit(-1);
	}
	int i;
	for (i = 0; i < _numFacilities; i++) {
		_sol[i] = 0;
	}
}

QAPSolution::~QAPSolution() {
	//
	_numFacilities = 0;
	_fitness = 0.0;
	delete [] _sol;
}

void QAPSolution::putObjectIn(int facility, int location) {
	_sol[facility] = location;
}

int QAPSolution::whereIsObject(int object) {
	return _sol[facility];
}

double QAPSolution::getFitness() const {
	return _fitness;
}

void QAPSolution::setFitness(double fitness) {
	_fitness = fitness;
}

void QAPSolution::copy(QAPSolution& solution) {

	/*
	 * 1. Copiar las asignaciones de objetos a mochilas
	 * 2. copiar el fitness
	 */
	for (int i = 0; i < _numFacilities; i++)
		_sol[i] = solution._sol[i];

	_fitness = solution.getFitness();
}
