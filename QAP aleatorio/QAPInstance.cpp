/*
 * QAPInstance.cpp
 *
 * Fichero que define los métodos de la clase QAPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPInstance.h"
#include "QAPSolution.h"
#include <fstream>

QAPInstance::QAPInstance() {
	//TODO completar inicializando las variables miembro
	_numFacilities = 0;
}


QAPInstance::~QAPInstance() {
	for(int i=0; i < _numFacilities; i++)
	{
		delete [] _flows[i];
		delete [] _distances[i];
	}

	delete [] _flows;
	delete [] _distances;
	_numFacilities = _numLocations = 0;

}



double QAPInstance::getSumCost(QAPSolution &solution) {

	double cost = 0.0;

	/*for(int i=0; i<_numLocations; i++)
	{
		cout << solution.whereIsObject(i)+1 << " ";
	}*/

	for (int i=0; i < _numFacilities; i++)
	{
		for(int j=0; j < _numFacilities; j++)
		{	
			//Si un edificio impar se pone en una localizacion impar se penaliza (*0.1)
			if(i%2!=0 && j%2!=0)
				cost += _flows[solution.whereIsFacility(i)][solution.whereIsFacility(j)] * _distances[i][j] * 1.10;
			else	
				cost += _flows[solution.whereIsFacility(i)][solution.whereIsFacility(j)] * _distances[i][j];
		}	

	}

	return cost;
}

void QAPInstance::readInstance(char *filename) {

	/*
	 *   1. leer el número de edificios/localizaciones
	 *   2. reservar la memoria de vectores y matrices
	 *   3. leer distancias y flujos de las localizaciones y edificios.
	 */
	ifstream fichero;
	fichero.open(filename);
	int dato;
	fichero >> dato;

	//leemos el numero de edificios que sera el mismo que le de localizaciones
	_numLocations = dato;
	_numFacilities = dato; 

	char cadena[256];
	fichero.getline(cadena, ' ');	//NOS SALTAMOS LA PRIMERA LINEA
	
	_flows = new int*[_numLocations];
	_distances = new int*[_numLocations];
	for(int i=0; i<_numLocations; i++)
	{
		_flows[i] = new int[_numLocations];
		_distances[i] = new int [_numLocations];
	}

	//3. Leer la matriz 
	//int aux; 
	for(int i = 0; i < _numLocations ; i++){
		for (int j = 0; j< _numLocations; j++){
			fichero >> dato;
			_flows[i][j] = dato;
			//std::cout << "Flujo "<<i<<" "<<j<<" :"<<dato<<"\n";
		}
	} 

	fichero.getline(cadena, ' ');	//NOS SALTAMOS
	
	for(int i = 0; i < _numLocations ; i++){
		for (int j = 0; j< _numLocations; j++){
			fichero >> dato;
			_distances[i][j] = dato;
			//std::cout << "distancia "<<i<<" "<<j<<" :"<<dato<<"\n";

		}
	} 

	fichero.close();
}
