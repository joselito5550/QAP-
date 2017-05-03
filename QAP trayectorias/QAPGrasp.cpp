/*
 * QAPGrasp.cpp
 *
 * Fichero que define las funciones de la clase QAPGrasp. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPGrasp.h"
#include <vector>
#include "QAPSimpleFirstImprovementNO.h"
#include "QAPLocalSearch.h"
#include <iostream>

using namespace std;

void QAPGrasp::chooseOperation(QAPObjectAssignmentOperation& operation) {

	//int bestObj = 0;
	//int bestKnapsack = 0;
	int bestIndexFacility1 = 0;
	int bestIndexFacility2 = 0;
	double bestDensity = 0;
	double bestDeltaFitness = 0;
	bool initialisedBestDensity = false;
	//unsigned numObjs = _instance->getNumLocations();
	//unsigned numKnapsacks = _instance->getNumLocations();
	unsigned numLocations = _instance->getNumLocations();

	/**
	 * Calcular el número de intentos como el porcentaje _alpha por el número de posibilidades, que es el número de objetos por el número de mochilas.
	 *
	 * En este paso no se considerará que ya haya objetos asignados a alguna mochila, la mochila 0 que representa objetos sin asignar a ninguna mochila, ni que haya mochilas ya completamente llenas
	 */
	//unsigned numTries = ((unsigned)(numObjs * numKnapsacks * _alpha));
	unsigned numTries = ((unsigned) (numLocations * _alpha));

	/**
	 * TODO
	 * Generar alternativas de objeto y mochila aleatorias (no se considera la mochila 0) 
	 y quedarse con la alterantiva de mejor densidad
	 */
	for (unsigned i = 0; i < numTries; i++) {
		//int indexObj = rand()%(numObjs);
		//int indexKnapsack = 1+rand()%(numKnapsacks);
		int indexFacility1 = rand()%numLocations;
		int indexFacility2 = rand()%numLocations;

		double deltaFitness = QAPEvaluator::computeDeltaFitness(*_instance,*_sol,indexFacility1,indexFacility2); //TODO obtener la mejora en fitness de dicha operación
		//double density = deltaFitness/(_instance->getWeight(indexObj)); //TODO calcular la densidad de dicha operación como la diferencia en fitness dividido por el peso del objeto
		double density = deltaFitness / (_instance->getFlow(indexFacility1));

		//TODO actualizar si resulta ser la mejor
		//DUDA sentencia if
		if (density > bestDensity || initialisedBestDensity == false) {
			initialisedBestDensity = true;
			bestDensity = density;
			//bestObj = indexObj;
			//bestKnapsack = indexKnapsack;
			bestIndexFacility1 = indexFacility1;
			bestIndexFacility2 = indexFacility2;
			bestDeltaFitness = deltaFitness;
		}
	}

	operation.setValues(bestIndexFacility1, bestIndexFacility2,	bestDeltaFitness);
}

void QAPGrasp::buildInitialSolution() {

	/**
	 * TODO
	 * Vaciar la solución _sol asignándole un fitness de 0 y poniendo todos los objetos en la mochila 0
	 */
	//unsigned numObjs = _instance->getNumObjs();
	unsigned numLocations = _instance->getNumLocations();
	_sol->setFitness(0);
	for (unsigned i = 0; i < numLocations; i++) {
		_sol->putFacility(i,0);
	}

	/** Seleccionar la primera operación */
	QAPObjectAssignmentOperation operation;
	chooseOperation(operation);

	/**
	 * TODO
	 * Mientras la operación tenga un incremento de fitness positivo, operation.getDeltaFitness(),
	 *  1. aplicar la operación en _sol
	 *  2. Almacenar el fitness de la solución en _result (para las gráficas)
	 *  3. seleccionar una nueva operación
	 */
	while (operation.getDeltaFitness() < 0) {
		operation.apply(*_sol);
		_results.push_back(_sol->getFitness()); //DUDA
		chooseOperation(operation);
	}
}

void QAPGrasp::initialise(double alpha, QAPInstance& instance) {

	_sol = new QAPSolution(instance);
	_bestSolution = new QAPSolution(instance);
	_bestSolution->copy(*_sol);
	_instance = &instance;
	_alpha = alpha;
}

void QAPGrasp::run(QAPStopCondition& stopCondition) {

	if (_sol == NULL) {
		cerr << "GRASP was not initialised" << endl;
		exit(-1);
	}

	/**
	 * TODO
	 * Mientras no se alcance el criterio de parada
	 *   1. Generar una solución inicial invocando al método correspondiente
	 *   2. Almacenar el fitness de la solución en _results
	 *   3. Optimizar _sol con la búsqueda local y el operador de vecindario de la metaheurística
	 *   4. Actualizar la mejor solución
	 */
	while (stopCondition.reached() == false) {
		//bui...
		buildInitialSolution();
		_results.push_back(_sol->getFitness());
		//_ls.optimise...
		_ls.optimise(*_instance,_no,*_sol);

		vector<double> &auxResults = _ls.getResults();

		for (auto result : auxResults){
			_results.push_back(result);
		}

		if (QAPEvaluator::compare(_sol->getFitness(), _bestSolution->getFitness()) < 0)
			_bestSolution->copy(*_sol);

		stopCondition.notifyIteration();
	}
}
