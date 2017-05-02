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
#include <iostream>

using namespace std;

void QAPIteratedGreedy::chooseOperation(QAPObjectAssignmentOperation& operation) {

	int bestObj = 0;
	int bestKnapsack = 0;
	double bestDensity = 0;
	double bestDeltaFitness = 0;
	bool initialisedBestDensity = false;
	unsigned numObjs = _instance->getNumObjs();
	unsigned numKnapsacks = _instance->getNumKnapsacks();

	/**
	 * TODO
	 * Recorrer todos los objetos que no están en ninguna mochila
	 *   Recorrer todas las mochilas
	 *     Calcular el delta del fitness de asignar dicho objeto a dicha mochila y la densidad
	 *     Almacenar dicha asignación como la mejor en caso de que sea la de mayor densidad
	 */

	for (unsigned i = 0; i < numObjs; i++) {

		int indexObj = i;

		if (_sol->whereIsObject(indexObj)==0) { //TODO comprobar que no está en ninguna mochila

			for (unsigned j = 1; j<=numKnapsacks; j++) { //TODO para todas las mochilas disponibles (saltarse la 0)

				//TODO Calcular delta fitness, densidad como deltaFitness dividido por el peso, y actualizar la mejor opción
				int indexKnapsack = j;

				double deltaFitness = QAPEvaluator::computeDeltaFitness(*_instance,*_sol, i,indexKnapsack);
				double density = deltaFitness / (_instance->getWeight(indexObj));

				if (deltaFitness > bestDeltaFitness || initialisedBestDensity == false) {
					initialisedBestDensity = true;
					bestDensity = density;
					bestObj = indexObj;
					bestKnapsack = indexKnapsack;
					bestDeltaFitness = deltaFitness;
				}
			}
		}
	}

	operation.setValues(bestObj, bestKnapsack, bestDeltaFitness);
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
	while (operation.getDeltaFitness() > 0) {
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

	unsigned numObjs = _instance->getNumObjs();

	for (unsigned i = 0; i < numObjs; i++){

		double randSample = ((double)(rand())) / RAND_MAX;

		if ( randSample  >= _alpha){ //DUDA no se si al compilar dara fallo al obtener _alpha, seguramente si, getAlpha en .h
			_sol->putObjectIn(i, 0);
		}
	}

	double fitness = QAPEvaluator::computeFitness(*_instance, *_sol);
	_sol->setFitness(fitness);
	_results.push_back(_sol->getFitness());
}

void QAPIteratedGreedy::initialise(double alpha, QAPInstance& instance) {
	_sol = new QAPSolution(instance);
	_bestSolution = new QAPSolution(instance);
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
	rebuild();

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


