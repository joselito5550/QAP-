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
	static double computeDeltaFitness(QAPInstance &instance, QAPSolution &solution, int indexFacility1, int indexFacility2);

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

	/**
	 * Función que realiza la comparación entre dos valores de fitness (sirve para especificar si es un problema de maximización o minimización)
	 * @param[in] f1 primer valor de fitness a comparar
	 * @param[in] f2 segundo valor de fitness a comparar
	 * @return Un valor positivo si el primer valor es mejor que el segundo, negativo en caso contrario, y 0 si son indistinguibles
	 */
	static double compare(double f1, double f2){
		/*double aux = 0;
		if(f1 > f2)
		//aux = 1;
		aux = -1;
		else if(f1<f2)
		//aux = -1;
		aux = 1;
		else aux = 0;
		return aux; //TODO corregir lo que hay que devolver*/
		return (f2-f1);
	}

	/**
	 * Función que indica si el problema es de minimización o de maximización
	 * @return Devuelve true si el problema es de minimización o false, si es de maximización
	 */
	/*static bool isToBeMinimised(){
		return (compare(0,1) > 0);
	}*/
	static bool isToBeMinimised(){
		return (compare(0,1) > 0);
	}
};

#endif
