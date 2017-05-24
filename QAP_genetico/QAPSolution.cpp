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
	_numFacilities = instance.getNumLocations();
	_fitness = 0;
	_sol = new int[_numFacilities];
	if (!_sol) {
		cerr << "No se ha reservado memoria correctamente para _sol" << endl;
		exit(-1);
	}
	//Vamos a inicializar a -1, nos sera util para Iterated Greedy
	for (int i = 0; i < _numFacilities; i++) {
		_sol[i] = -1;
	}
}

QAPSolution::~QAPSolution() {
	//
	_numFacilities = 0;
	_fitness = 0.0;
	delete [] _sol;
}

void QAPSolution::putFacility(int facility, int location){
	//la función asigna un edificio a una localizacion, modificador.
	_sol[facility] = location;

}

int QAPSolution::whereIsFacility(int facility){
	//la función devuelve la localizacion en la que se encuentra insertado un edificio sol[i]
	return(_sol[facility]);
}

double QAPSolution::getFitness() const {
	return _fitness;
}

void QAPSolution::setFitness(double fitness) {
	_fitness = fitness;
}

void QAPSolution::copy(Solution& solution) {

	/*
	 * 1. Copiar las asignaciones de objetos a mochilas
	 * 2. copiar el fitness
	 */
 	QAPSolution &auxSol = (QAPSolution&) solution;
	for (int i = 0; i < _numFacilities; i++)
		_sol[i] = auxSol._sol[i];
	_fitness = auxSol._fitness;
	_fitnessAssigned = auxSol._fitnessAssigned;
}

void QAPSolution::intercambio(int &l1, int &l2){

	int i1=whereIsFacility(l1);
	int i2=whereIsFacility(l2);

	/*
	putFacility(i1,l2);
	putFacility(i2,l1);*/
	putFacility(l2, i1);
	putFacility(l1, i2);
}

bool QAPSolution::existeIns(int ins){ //¿Existe en el vector solución el edificio pasado como parámetro?
	
	for(int l=0; l< _numFacilities; l++)
	{
		if(_sol[l] == ins)
			return true;
	}
	return false;
}
