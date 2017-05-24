/**
 * QAPEvaluator.h
 * 
 * Fichero que define la clase QAPEvaluator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
*/

#ifndef __QAPEvaluator_H__
#define __QAPEvaluator_H__

#include "QAPInstance.h"
#include "QAPSolution.h"

/**
 * Clase que calcula el fitness de una solución al problema QAP
 */

class QAPEvaluator {

protected:
	/**
	 * Variable donde se contabiliza el número de soluciones que se evalúan a través de  computeFitness o computeDeltaFitness
	 */
	static unsigned _numEvaluations;

public:
	/**
	 * Función que calcula el fitness de una solución
	 * @param[in] instance Referencia a un objeto con la información de la instancia del problema QAP
	 * @param[in] solution Referencia a un objeto que representa una solución al problema.
	 * 
	 * @return Fitness de la solución. Será negativa si se viola la capacidad de alguna mochila y positiva si la solución es factible. En ese caso, el valor es igual a la suma de los beneficios individuales y cuadráticos
	 */
	static double computeFitness(QAPInstance &instance, QAPSolution &solution);

	/**
	 * Función que calcula la diferencia en fitness si a la solución se le aplicase la asignación del objeto indexObject a la mochila indexKnapsack
	 * @param[in] instance Referencia a un objeto con la información de la instancia del problema QAP
	 * @param[in] solution Referencia a un objeto que representa una solución al problema.
	 * @param[in] indexObject Índice del objeto que se pondría en otra mochila
	 * @param[in] indexKnapsack Índice de la mochila donde se pondría el objeto. Puede ser 0, indicando que se saca el objeto de la mochila en la que esté
	 *
	 * @return Diferencia en fitness si a la solución se le aplicase la asignación del objeto indexObject a la mochila indexKnapsack
	 */
	static double computeDeltaFitness(QAPInstance &instance, QAPSolution &solution, int indexObject, int indexKnapsack);

	/**
	 * Función que resetea la variable interna que contabiliza el número de evaluaciones
	 */
	static void resetNumEvaluations();

	/**
	 * Función que devuelve el número de veces que se ha evaluado alguna solución
	 */
	static unsigned getNumEvaluations() {
		return _numEvaluations;
	}

	
};

#endif