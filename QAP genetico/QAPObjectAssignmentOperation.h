/* QAPObjectAssignmentOperation.h
 *
 * Fichero que declara la clase QAPObjectAssignmentOperation. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef __QAPOBJECTASSIGNMENTOPERATION_H__
#define __QAPOBJECTASSIGNMENTOPERATION_H__

#include "QAPChangeOperation.h"
#include "QAPSolution.h"

/**
 * Clase que codifica una operación de asignación de una instalación a una localización
 */
class QAPObjectAssignmentOperation : public QAPChangeOperation {

protected:

	int _indexLoc1;
	int _indexLoc2;
	double _deltaFitness;

public:

	/**
	 * Constructor
	 */
	QAPObjectAssignmentOperation();


	/**
	 * Destructor
	 */
	virtual ~QAPObjectAssignmentOperation();

	/**
	 * Función que aplica el cambio que define el propio objeto sobre la solución que recibe como argumento.
	 * @param[in, out] solution Objeto solución sobre el que se aplicará el cambio
	 */
	virtual void apply(QAPSolution &solution);

	/**
	 * Función que asigna los valores la operación
	 * @param[in] indexObject El índice del objeto que se va a cambiar de mochila
	 * @param[in] indexKnapsack El índice de la mochila donde se insertará el objeto
	 * @param[in] deltaFitness La diferencia en fitness de aplicar dicha operación de asignación de un objeto a una mochila (siempre que la solución actual no se hubiese cambiado cuando se calculo dicha diferencia)
	 */
	void setValues(int indexLoc1, int indexLoc2, double deltaFitness);


};

#endif