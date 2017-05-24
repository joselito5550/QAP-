/*
 * QAPNeighExplorer.h
 *
 * Fichero que define la clase QAPNeighExplorer. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef INCLUDE_QAPNEIGHEXPLORER_H_
#define INCLUDE_QAPNEIGHEXPLORER_H_

#include "QAPSolution.h"
#include "QAPInstance.h"
#include "QAPChangeOperation.h"

/**
 * clase abstracta que define las operaciones de cualquier operador que explora la vecindad de una solución dada.
 */
class QAPNeighExplorer {
public:

	/**
	 * Destructor
	 */
	virtual ~QAPNeighExplorer(){}

	/**
	 * Función que busca una operación que aplicada a la solución devuelva otra solución vecina. Se utilizará para buscar una solución vecina que la mejore, o la mejor de las soluciones vecinas.
	 *
	 * @param[in] instance Instancia del problema de la múltiples mochilas cuadráticas
	 * @param[in] solution Solución cuya vecindad va a ser explorada
	 * @param[out] operation Operación que se devuelve al explorar la vecindad.
	 *
	 * @return Devuelve verdadero si ha encontrado una operación válida, que mejora la solution y que se ha almacenado en operation. Falso en otro caso
	 */
	virtual bool findOperation(QAPInstance &instance, QAPSolution &solution, QAPChangeOperation &operation) = 0;
};



#endif /* INCLUDE_QAPNEIGHEXPLORER_H_ */
