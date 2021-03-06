/*
 * QAPSimulatedAnnealing.cpp
 *
 * Fichero que define las funciones de la clase QAPSimulatedAnnealing. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPSimulatedAnnealing.h"
#include "QAPSolution.h"
#include "QAPSolGenerator.h"
#include "QAPEvaluator.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

void QAPSimulatedAnnealing::setSolution(QAPSolution* solution) {
	if (_T <= 0 || _annealingFactor <= 0){
		cerr << "Simulated annealing has not been initialised" << endl;
		exit(-1);
	}

	if (_solution != NULL){
		cerr << "No se debe invocar más de una vez el método QAPTabuSearch::setSolution" << endl;
		exit(1);
	}

	this->_solution = solution;

	if (_bestSolution == NULL){
		_bestSolution = new QAPSolution(*_instance);
	}

	_bestSolution->copy(*solution);
}

void QAPSimulatedAnnealing::run(QAPStopCondition& stopCondition) {

	if (_T <= 0 || _annealingFactor <= 0){
		cerr << "Simulated annealing has not been initialised" << endl;
		exit(-1);
	}

	if (_solution == NULL){
		cerr << "Simulated annealing has not been given an initial solution" << endl;
		exit(-1);
	}

	_results.clear();
	//unsigned numObjs = _instance->getNumObjs();
	//unsigned numKnapsacks = _instance->getNumKnapsacks();
	unsigned numFacilities = _instance -> getNumLocations();
	unsigned numIterations = 0;

	/**
	 * TODO
	 * Mientras que no se alcance la condición de parada
	 *   1. Generar aleatoriamente un objeto y una mochila (incluida la mochila 0)
	 *   2. Calcular la diferencia en fitness de aplicar dicho cambio sobre _solution
	 *   3. Consultar si se acepta el cambio
	 *   4. Actualizar la mejor solución hasta el momento.
	 *   5. Si se llevan _itsPerAnnealing tras el último enfriamiento, entonces enfriar
	 */
	while (stopCondition.reached()==false){
		//int indexObject = rand()%numObjs;
		//int indexKnapsack = rand()%(numKnapsacks+1);
		int indexFacility1 = rand()%numFacilities;
		int indexFacility2 = rand()%numFacilities;

		double deltaFitness = QAPEvaluator::computeDeltaFitness(*_instance, *_solution, indexFacility1, indexFacility2);

		if (accept(deltaFitness)){
			//_solution->putFacility(indexFacility1, indexFacility2);
			//_solution->setFitness(_solution->getFitness() + deltaFitness);
			int location1 = _solution->whereIsFacility(indexFacility1);
			int location2 = _solution->whereIsFacility(indexFacility2);
			_solution->putFacility(indexFacility1, location2);
			_solution->putFacility(indexFacility2, location1);
			_solution->setFitness(_solution->getFitness() + deltaFitness);
			if (QAPEvaluator::compare(_solution->getFitness(), _bestSolution->getFitness()) > 0){
				_bestSolution->copy(*_solution);
				//setSolution(_solution);
			}
		}
		numIterations++;
		_results.push_back(_solution->getFitness());

		if (numIterations % _itsPerAnnealing){	//...
			_T *= _annealingFactor;
		}

		stopCondition.notifyIteration();
	}
}

bool QAPSimulatedAnnealing::accept(double deltaFitness) {
	/**
	 * TODO
	 * .Calcular la probabilidad de aceptar el cambio, que será la exponencial de (la diferencia de fitness dividido por la temperatura)
	 *
	 * .Si el problema es de minimización, entonces un delta fitness negativo es bueno. 
	 	Hay que modificar "un poco" la función de aceptación para producir una probabilidad de aceptación superior a 1
	 *
	 * .Generar un aleatorio entre 0 y 1
	 * .Devolver true si el aleatorio es inferior a la probabilidad de aceptación.
	 *
	 * (piensa qué ocurre cuando la diferencia de fitness es positiva o cuando es negativa)
	 */

	//double auxDeltaFitness = exp(deltaFitness/_T);
	double auxDeltaFitness = deltaFitness;

	if (QAPEvaluator::isToBeMinimised()){
		auxDeltaFitness *= -1;
	}

	
	//double randSample = (((double)rand()) / RAND_MAX);
	//return (randSample < auxDeltaFitness);  
	double prob = exp(auxDeltaFitness / _T);
	double randSample = ((double)rand() / RAND_MAX);
	return (randSample < prob);
	//DUDA entonces para que es el auxDeltaFitness? si nos fijamos solo en el numero aleatorio y la prob de aceptacion
}

void QAPSimulatedAnnealing::initialise(double initialProb, int numInitialEstimates, double annealingFactor, unsigned itsPerAnnealing, QAPInstance &instance) {
	_initialProb = initialProb;
	_annealingFactor = annealingFactor;
	_instance = &instance;
	_itsPerAnnealing = itsPerAnnealing;
	//int numObjs = instance.getNumObjs();
	//int numKnapsacks = instance.getNumKnapsacks();
	int numFacilities = _instance -> getNumLocations();
	double averageFDiffs = 0.;

	/**
	 * Inicialización de la temperatura.
	 * Para ello, se generan una serie de soluciones iniciales y de vecinos. Se calcula la diferencia media de fitness hacia peores soluciones y se despeja la temperatura de la función de aceptación
	 */

	for (int i = 0; i < numInitialEstimates; i++){
		QAPSolution sol(instance);
		QAPSolGenerator::genRandomSol(instance, sol);
		sol.setFitness(QAPEvaluator::computeFitness(instance, sol));
		//int indexObject = rand() % numObjs;
		//int indexKnapsack = rand() % (numKnapsacks + 1);
		int indexFacility1 = rand()%numFacilities;
		int indexFacility2 = rand()%numFacilities;
		double deltaFitness = QAPEvaluator::computeDeltaFitness(instance, sol, indexFacility1, indexFacility2);
		averageFDiffs += max(fabs(deltaFitness),10.); //He puesto una diferencia mínima de 10 para evitar cambios en el fitness demasiado pequeños (por ejemplo, cuando se modifica una mochila que no es la de la máxima violación (este método se podría mejorar)
	}

	averageFDiffs /= numInitialEstimates;

	_T = -1. * averageFDiffs / log(initialProb);
}
