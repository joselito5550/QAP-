/*
 * QAPIteratedGreedy.cpp
 *
 * Fichero que define las funciones de la clase QAPIteratedGreedy. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPIteratedGreedy.h"
#include "QAPObjectAssignmentOperation.h"
#include "QAPSolution.h"
#include "QAPSolGenerator.h"
#include <iostream>
#include <algorithm> 

using namespace std;

void QAPIteratedGreedy::chooseOperation(QAPObjectAssignmentOperation& operation) {


	int bestIndexFacility1 = 0;
	int bestIndexFacility2 = 0;

	double bestDeltaFitness = 0;

	bool initialisedBestDeltaFitness = false;

	unsigned numLocations = _instance -> getNumLocations();

	//cout << " Antes : ";
	//_sol->imprimeSolucion();
	unsigned j = 0;
	for(unsigned i = 0; i < numLocations; i++)
	{
		if(_sol->whereIsFacility(i) == -1)
		{
			_sol->putFacility(i, _destruidas[j]);
			j++;
		}
	}
	//cout << " Despues : "; 
	//_sol->imprimeSolucion();

	/**
	 * TODO
	 * Recorrer todos los objetos que no están en ninguna mochila
	 *   Recorrer todas las mochilas
	 *     Calcular el delta del fitness de asignar dicho objeto a dicha mochila y la densidad
	 *     Almacenar dicha asignación como la mejor en caso de que sea la de mayor densidad
	 */


	


	


}

void QAPIteratedGreedy::rebuild() {

	/** Seleccionar la primera operación */
	QAPObjectAssignmentOperation operation;
	chooseOperation(operation);
	/** TODO
	 * Mientras la operación tenga un incremento de fitness positivo, operation.getDeltaFitness(),
	 *  1. aplicar la operación en _sol
	 *  2. Almacenar el fitness de la solución en _result (para las gráficas)
	 *  3. seleccionar una nueva operación
	 */
		double fitness = QAPEvaluator::computeFitness(*_instance, *_sol);
	_sol->setFitness(fitness);
	_results.push_back(_sol->getFitness());

	while (operation.getDeltaFitness() < 0) {
		//1. Aplicar la operación en _sol
		operation.apply(*_sol);
		//2. Almacenar el fitness de la solución en _result (para las gráficas)
		_results.push_back(_sol->getFitness());
		//3. Seleccionar una nueva operacion
		chooseOperation(operation);
	}
}

void QAPIteratedGreedy::destroy() {

	/**
	 * TODO
	 * Recorrer los objetos y sacarlos de su mochila con probabilidad _alpha
	 */

	unsigned numLocations = _instance->getNumLocations();
	unsigned j = 0;

	_destruidas.clear();

	for (unsigned i = 0; i < numLocations; i++){

		double randSample = ((double)(rand())) / RAND_MAX;

		if ( randSample  <= _alpha){
			_destruidas.push_back(_sol->whereIsFacility(i));
			_sol->putFacility(i, -1);
		}
	}
	random_shuffle ( _destruidas.begin(), _destruidas.end() );
	//imprime(_destruidas);


}

void QAPIteratedGreedy::initialise(double alpha, QAPInstance& instance) {
	_sol = new QAPSolution(instance);
	_bestSolution = new QAPSolution(instance);
	QAPSolution initialSolution(instance);
	//Generamos solucion aleatoria
	QAPSolGenerator::genRandomSol(instance, *_sol);
	_bestSolution->copy(*_sol);
	_instance = &instance;
	_alpha = alpha;
}

void QAPIteratedGreedy::run(QAPStopCondition& stopCondition) {

	if (_sol == NULL) {
		cerr << "IG was not initialised" << endl;
		exit(-1);
	}

	/** Crear la primera solución */
	//rebuild();
	//_sol->imprimeSolucion();

	if (QAPEvaluator::compare(_sol->getFitness(), _bestSolution->getFitness()) > 0)
		_bestSolution->copy(*_sol);

	/**
	 * TODO
	 * Mientras no se alcance la condición de parada
	 *  1. Destruir parcialmente la solución
	 *  2. Reconstruir la solución
	 *  3. Almacenar el nuevo fitness en _results para las gráficas
	 *  4. Actualizar la mejor solución y volver a ella si la nueva es peor
	 */

	while (stopCondition.reached() == false) {
		destroy();
		rebuild();
		_results.push_back(_sol->getFitness());

		if (QAPEvaluator::compare(_sol->getFitness(), _bestSolution->getFitness()) > 0){
			 _bestSolution->copy(*_sol);
			 _bestSolution->setFitness(_sol->getFitness());
		}
			//...
		else
			_sol->copy(*_bestSolution);//DUDA
			//Volver a ella si la nueva es peor sería dejarlo como esta no?

		stopCondition.notifyIteration();
	}
}

