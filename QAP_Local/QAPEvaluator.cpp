/*
 * QAPEvaluator.cpp
 *
 * Fichero que define los métodos de la clase QAPEvaluator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPEvaluator.h"
#include "QAPInstance.h"
#include "QAPSolution.h"

unsigned QAPEvaluator::_numEvaluations = 0;

double QAPEvaluator::computeFitness(QAPInstance &instance, QAPSolution &solution){

	double fitness = 0;

	/*
	 *  Calcular el fitness de la solución de la siguiente forma
	 *   1. Obtener la máxima violación de las capacidades de las mochilas invocando la función de arriba
	 *   2. Si es mayor a 0, entonces devolvemos dicha mayor violación multiplicada por -1.
	 *   3. Si no, devolvemos la suma de los beneficios individuales y cuadráticos invocando a la función de arriba
	 */
	 // if(instance.getMaxCapacityViolation(solution) > 0)
	 // {
	 // 	fitness = instance.getMaxCapacityViolation(solution) * (-1);
	 // }
	 // else
	 // {
	 // 	fitness = instance.getSumProfits(solution);
	 // }

	 fitness = instance.getSumCost(solution);
	 _numEvaluations++;
	return fitness;
}

double QAPEvaluator::computeDeltaFitness(QAPInstance& instance,	QAPSolution& solution, int indexFacility1, int indexFacility2) {

	_numEvaluations++;

	/**
	 * TODO
	 * Dado que el fitness depende de si se violan las capacidades de alguna mochila o no,
	 * deben calcularse las violaciones actuales y las posibles nuevas, además del posible
	 * cambio en la suma de beneficios
	 *
	 * 1. Obten la máxima violación actual
	 * 2. Invoca a QAPInstance.getDeltaMaxCapacityViolation para que devuelva como se modifica la máxima violación tras la operación
	 * 3. Suma las medidas anteriores para obtener la máxima violación si se aplica la operación
	 * 4. Obten la suma de beneficios actual
	 * 5. Invoca a QAPInstance.getDeltaSumProfits para que devuelva cómo se modifica la suma de beneficios si se aplica la operación
	 * 6. Suma las dos medidas anteriores para obtener la suma de beneficios si se aplica la operación
	 *
	 * Finalmente
	 * Si las violaciones actuales y nuevas son positivas, devuelve el negativo de deltaMaxCapacityViolation
	 * Si ambas violaciones son 0, devuelve el deltaSumProfits
	 * Si sólo la violación actual es positiva y la nueva es 0, devuelve la suma de newSumProfits + el negativo de deltaMaxCapacityViolation
	 * Si sólo la violación nueva es positiva, devuelve el negativo de (la suma de la nueva violación + la nueva violación de capacidades)
	 */

	/*double actualMaxViolation = instance.getMaxCapacityViolation(solution);
	double deltaMaxCapacityViolation = instance.getDeltaMaxCapacityViolation(solution, indexObject, indexKnapsack);
	double newMaxViolation = actualMaxViolation + deltaMaxCapacityViolation;
	double actualSumProfits = instance.getSumProfits(solution);
	double deltaSumProfits = instance.getDeltaSumProfits(solution, indexObject, indexKnapsack);
	double newSumProfits = actualSumProfits + deltaSumProfits;

	if (actualMaxViolation > 0 && newMaxViolation > 0)
		return deltaMaxCapacityViolation*-1;
	else if (actualMaxViolation == 0 && deltaMaxCapacityViolation == 0)
		return deltaSumProfits;
	else if (actualMaxViolation > 0)
		return (newSumProfits + deltaMaxCapacityViolation*-1);
	else 
		return (actualSumProfits*-1 + newMaxViolation*-1);*/
	double fitness = 0;
	fitness = instance.getDeltaSumCost(solution, indexFacility1, indexFacility2);
	return fitness;

}

void QAPEvaluator::resetNumEvaluations() {
	_numEvaluations = 0;
}
