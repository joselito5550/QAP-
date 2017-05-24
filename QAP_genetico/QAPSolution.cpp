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

	_numLocalizaciones = instance.getNumLoc();
	_fitness = 0;
	_fitnessAssigned = false;
	
	_sol = new int[_numLocalizaciones];


	if (!_sol) {
	cerr << "No se ha reservado memoria correctamente para _sol" << endl;
	exit(-1);
	}
	int i;
	for (i = 0; i < _numLocalizaciones; i++) {
	_sol[i] = -1;
	}
	
}

QAPSolution::~QAPSolution() {

	_numLocalizaciones = 0;
	_fitness = 0;
	delete [] _sol;
}

void QAPSolution::putInstalacion(int instalacion, int localizacion) {
	_sol[localizacion] = instalacion;
	_fitnessAssigned = false;

}

int QAPSolution::whereIsInstalacion(int instalacion) {
	
	int localizacion=0;

	for(int i=0; i < _numLocalizaciones; i++)
	{	
		if(_sol[i]==instalacion){
			localizacion=i;
		}
	}

	return localizacion;
}

int QAPSolution::whatIsInLocalizacion(int localizacion){
	return _sol[localizacion];
}

double QAPSolution::getFitness() const {
	return _fitness;
}

void QAPSolution::setFitness(double fitness) {
	_fitness = fitness;
	_fitnessAssigned = true;

}

void QAPSolution::copy(Solution& solution) {

	/* TODO
	 * 1. Copiar las asignaciones de instalaciones a localizaciones
	 * 2. copiar el fitness
	 */

 	QAPSolution &auxSol = (QAPSolution&) solution;
	for (int i = 0; i < _numLocalizaciones; i++)
		_sol[i] = auxSol._sol[i];
	_fitness = auxSol._fitness;
	_fitnessAssigned = auxSol._fitnessAssigned;
}

void QAPSolution::intercambio(int &l1, int &l2){

	int i1=whatIsInLocalizacion(l1);
	int i2=whatIsInLocalizacion(l2);

	putInstalacion(i1,l2);
	putInstalacion(i2,l1);	
}

bool QAPSolution::existeIns(int ins){ //¿Existe en el vector solución el edificio pasado como parámetro?
	
	for(int l=0; l< _numLocalizaciones; l++)
	{
		if(_sol[l] == ins)
			return true;
	}
	return false;
}