/*
 * QAPSolution.cpp
 *
 * Fichero que define los métodos de la clase QAPSolution. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPSolution.h"
#include "QAPInstance.h"

QAPSolution::QAPSolution(QAPInstance &instance){

	_numFacilities = instance.getNumLocations();
	_fitness = 0.0;
	_sol= new int[_numFacilities];

	if (!_sol) {
		cerr << "No se ha reservado memoria correctamente para _sol" << endl;
		exit(-1);
	}

	for(int i=0; i < _numFacilities; i++){
		_sol[i] = 0;
	}
}

QAPSolution::~QAPSolution() {
	_numFacilities = 0;
	_fitness = 0.0;
	delete [] _sol;
}

void QAPSolution::putFacility(int facility, int location){
	//TODO completar la función asigna un edificio a una localizacion, modificador.
	_sol[facility] = location;

}

int QAPSolution::whereIsFacility(int facility){
	//TODO completar la función devuelve la localizacion en la que se encuentra insertado un edificio sol[i]
	return(_sol[facility]);


}
