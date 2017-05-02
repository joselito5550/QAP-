/*
 * QAPChangeOperation.h
 *
 * Fichero que declara la clase QAPChangeOperation. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef __QAPCHANGEOPERATION_H__
#define __QAPCHANGEOPERATION_H__

#include "QAPSolution.h"

/**
 * Clase abstracta para representar cualquier operación de modificación sobre una solución.
 */
class QAPChangeOperation{
public:

	/**
	 * Destructor
	 */
	virtual ~QAPChangeOperation(){
	}

	/**
	 * Función que aplica el cambio que define el objeto sobre la solución que recibe como argumento
	 * @param[in,out] solution Objeto solución sobre el que se aplicará el cambio
	 */
	virtual void apply(QAPSolution &solution) = 0;
};

#endif
