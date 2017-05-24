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

//aleatorios:
#include <ctime>

using namespace std;

QAPInstance::QAPInstance() {
	// inicializando las variables miembro
	_localizaciones = 0;
	_instalaciones = 0;
	this->_distancias = NULL;
	this->_flujos = NULL;
}

QAPInstance::~QAPInstance() {
	
	int i;
	for (i = 0; i < getNumLoc(); i++) {
		delete[] _distancias[i];
		delete[] _flujos[i];		
	}
	delete[] _distancias;
	delete[] _flujos;
	_localizaciones = _instalaciones = 0;
}


double QAPInstance::getSumCoste(QAPSolution &solution) {

	double sumCoste = 0.;

	int i, j;
	for(i=0; i < getNumIns(); i++)
	{
		for (j=0; j < getNumIns(); j++)
		{
				//Si la instalación es par y va a una localización par, no se penaliza
				if(i%2==0 && j%2==0)
				{
					sumCoste += getFlujo(solution.whereIsInstalacion(i),solution.whereIsInstalacion(j)) * getDistancia(i,j);
				}
				else
				{
					sumCoste += getFlujo(solution.whereIsInstalacion(i),solution.whereIsInstalacion(j)) * getDistancia(i,j) * PENALIZACION;
				}
	
		}
	}

	return sumCoste;
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

	ifstream fe;
	fe.open(filename,ifstream::in);
	if(!fe){
		cerr << "Error en la apertura del fichero: " << filename << endl;
		exit(-1);
	}

	int aux;
	fe >> aux;
	//cout << "numLoc " << aux <<endl<<endl;
	_localizaciones = aux;
	_instalaciones = aux;

	string linea;
	getline(fe, linea, '\n'); //Descartamos la primera línea

	_distancias = new double * [getNumLoc()];
	_flujos = new double * [getNumLoc()];
	
	if(!_distancias)
	{
		cerr << "Error al reservar memoria para distancias" << endl;
		exit(-1);
	}
	if(!_flujos)
	{
		cerr << "Error al reservar memoria para flujos" << endl;
		exit(-1);
	}

	int i,j;
	for(i=0; i < getNumLoc(); i++){
		_distancias[i] = new double [getNumLoc()];
		_flujos[i] = new double [getNumLoc()];
	}

	/*for(i=0; i<getNumLoc(); i++)
	{
		fe >> _profits[i][i];
	}*/

	for(i=0; i < getNumLoc(); i++)
	{
		for (j=0; j < getNumLoc(); j++)
		{
			fe >> _flujos[i][j];
		}
	}

	getline(fe, linea, '\n');

	for(i=0; i < getNumLoc(); i++)
	{
		for (j=0; j < getNumLoc(); j++)
		{
			fe >> _distancias[i][j];
		}
	}

	fe.close();
}


void QAPInstance::randomPermutation(int size, vector<int>& perm) {

	/** TODO
	 * 1. Vacía el vector perm
	 * 2. Llénalo con la permutación identidad
	 * 3. Recórrelo intercambiando cada elemento con otro escogido de forma aleatoria.
	 */
	 
//	 srand(time(NULL)); <-- Lo está inicializando en el main con una semilla tal que así: srand(seeds[0]);

	 int aux;
	 int numAleatorio;

	 perm.clear();
	 for(int i = 0; i < size; i++){
	 	perm.push_back(i);
	 }

	 for(int i = 0; i < size; i++){
	 	numAleatorio = rand()%size;
	 	aux = perm[i];
	 	perm[i] = perm[numAleatorio];
	 	perm[numAleatorio] = aux;
	 }

}

double QAPInstance::getDeltaSumCoste(QAPSolution& solution, int localizacion1, int localizacion2) {

	double deltaSumCoste = 0.0;

	double sumCosteInicial = getSumCoste(solution);

	solution.intercambio(localizacion1,localizacion2);

	double sumCostePosterior = getSumCoste(solution);

	solution.intercambio(localizacion1,localizacion2);

	return (sumCostePosterior - sumCosteInicial);

}