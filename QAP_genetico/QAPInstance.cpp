/*
 * QAPInstance.cpp
 *
 * Fichero que define los métodos de la clase QAPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPInstance.h"
#include "QAPSolution.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

#include <limits> 

using namespace std;

QAPInstance::QAPInstance() {
	// inicializando las variables miembro

	_numLocations = 0;
	_numFacilities = 0;
	this->_distances = NULL;
	this->_flows = NULL;
	
}


QAPInstance::~QAPInstance() {
	//
	int i;
	for (i = 0; i < getNumLocations(); i++) {
		delete[] _flows[i];
		delete[] _distances[i];
	}
	delete[] _flows;
	delete[] _distances;
	_numLocations = _numFacilities = 0;
}


double QAPInstance::getSumCost(QAPSolution &solution) {


	double cost = 0.0;

	/*for(int i=0; i<_numLocationss; i++)
	{
		cout << solution.whereIsObject(i)+1 << " ";
	}*/

	for (int i=0; i < _numFacilities; i++)
	{
		for(int j=0; j < _numFacilities; j++)
		{	
			//Al inicializarse a -1 los edificios no debemos evaluar -1 porque daría error de desborde.
			if(solution.whereIsFacility(i) != -1)
			{
				//Si un edificio impar se pone en una localizacion impar se penaliza (*0.1)
				if(i%2!=0 && j%2!=0)
					cost += _flows[solution.whereIsFacility(i)][solution.whereIsFacility(j)] * _distances[i][j] * 1.10;
				else	
					cost += _flows[solution.whereIsFacility(i)][solution.whereIsFacility(j)] * _distances[i][j];
			} 
		}

	}

	return cost;
}


void QAPInstance::readInstance(char *filename) {

	/*
	 *   1. leer el número de objetos
	 *   2. reservar la memoria de vectores y matrices
	 *   3. leer beneficios y pesos de los objetos según lo comentado arriba
	 *   4. Calcular las capacidades de las mochilas:
	 *      . Calcular la suma de los pesos de todos los objetos
	 *      . Multiplicar por 0.8
	 *      . Dividir el resultado anterior entre el número de mochilas. Eso será la capacidad de cada mochila
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


void QAPInstance::randomPermutation(int size, vector<int>& perm) {

	/** TODO
	 * 1. Vacía el vector perm
	 * 2. Llénalo con la permutación identidad
	 * 3. Recórrelo intercambiando cada elemento con otro escogido de forma aleatoria.
	 */
	int numero;
	//srand(time(NULL));
	perm.clear();

	for (int i=0; i<size; i++)
	{
		perm.push_back(i);
	}

	for (int i=0; i<size; i++)
	{
		numero = rand () % size;
		int aux = perm[i];
		perm[i]=perm[numero];
		perm[numero]=aux;
	}
}
double QAPInstance::getDeltaSumCost(QAPSolution& solution, int indexFacility1, int indexFacility2) {
	double deltaSumProfits = 0.0;

	int location1 = solution.whereIsFacility(indexFacility1);
	int location2 = solution.whereIsFacility(indexFacility2);

	double actualSumCost = 0.0;
	actualSumCost = getSumCost(solution);

	solution.putFacility(indexFacility1, location2);
	solution.putFacility(indexFacility2, location1);
	
	deltaSumProfits = getSumCost(solution) - actualSumCost;

	solution.putFacility(indexFacility1, location1);
	solution.putFacility(indexFacility2, location2);

	return deltaSumProfits;


}
