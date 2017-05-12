
/**
 * QAPSolGenerator.h
 * 
 * Fichero que define la clase QAPSolGenerator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
*/


#ifndef __QAPSOLGENERATOR_H__
#define __QAPSOLGENERATOR_H__

#include "QAPInstance.h"
#include "QAPSolution.h"

/**
 * Clase que genera una solución aleatoria al problema QAP
 *
 * Sobre la representación de soluciones:
 * La representación de las soluciones será un vector de número enteros: de 1 a M para objetos que están en alguna de las M mochilas y 0 para objetos que no están en ninguna mochilas
 */
struct Randomhelp{
	int num;
	bool used = false;
};
class QAPSolGenerator {

public:

	/**
	 * Función que genera una solución aleatoria para el problema de las múltiples mochilas cuadráticas
	 * @param[in] instance Referencia a un objeto con la información de la instancia del problema QAP
	 * @param[out] solution Referencia a un objeto que representa una solución al problema. IMPORTANTE: debe estar correctamente inicializado. En particular, su vector interno debe haber sido reservado previamente.
	 */
	static void genRandomSol(QAPInstance &instance, QAPSolution &solution);
};

#endif
