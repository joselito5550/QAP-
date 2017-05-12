/*
 * MKPSimpleBestImprovementNO.h
 *
 *  Created on: Jan 29, 2017
 *      Author: carlos
 */

#ifndef INCLUDE_QAPSIMPLEBESTIMPROVEMENTNO_H_
#define INCLUDE_QAPSIMPLEBESTIMPROVEMENTNO_H_

#include "QAPNeighExplorer.h"
#include "QAPSolution.h"
#include "QAPChangeOperation.h"
/**
 * Clase que se encarga de explorar el vecindario de una solución dada, devolviendo la mejor operación de asignación de un objeto a una mochila entre las operaciones posibles, devolverá FALSE si la operación devuelta no mejora a la solución actual
 */
class QAPSimpleBestImprovementNO : public QAPNeighExplorer{

public:

	/**
	 * Destructor
	 */
	virtual ~QAPSimpleBestImprovementNO(){

	}

	/**
	 * Función que explora el vecindario de una solución dada, devolviendo la mejor operación de asignación de un objeto a una mochila entre las operaciones posibles, devolverá FALSE si la operación devuelta no mejora a la solución actual
	 * @param[in] instance Instancia del problema
	 * @param[in] solution Solución cuya vecindad se va a explorar
	 * @param[out] operation Operación tal que aplicada a la solución, devuelve una vecina.
	 *
	 * @return true si la operación devuelta mejora a solution; false, si no hay ninguna operación en la vecindad que pueda mejorar a solution
	 */
	virtual bool findOperation(QAPInstance &instance, QAPSolution &solution, QAPChangeOperation &operation);

};


#endif /* INCLUDE_QAPSIMPLEBESTIMPROVEMENTNO_H_ */
