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
#include <time.h>
#include <stdlib.h>

/**
 * Clase que calcula el fitness de una solución al problema QAP
 */
class QAPEvaluator {

public:
	/**
	 * Función que calcula el fitness de una solución
	 * @param[in] instance Referencia a un objeto con la información de la instancia del problema QAP
	 * @param[in] solution Referencia a un objeto que representa una solución al problema.
	 * 
	 * @return Fitness de la solución. Será negativa si se viola la capacidad de alguna mochila y positiva si la solución es factible. En ese caso, el valor es igual a la suma de los beneficios individuales y cuadráticos
	 */
	static double computeFitness(QAPInstance &instance, QAPSolution &solution);
};

#endif
