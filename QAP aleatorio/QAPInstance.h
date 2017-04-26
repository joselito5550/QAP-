/**
 * QAPInstance.h
 *
 * Fichero que define la clase QAPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef __QAPINSTANCE_H__
#define __QAPINSTANCE_H__

#ifndef __QAPSOLUTION_H__
#include "QAPSolution.h"
#else
class QAPSolution;
#endif

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


/**
 * Clase que almacena la información de una instancia del problema QAP
 */
class QAPInstance {
protected:
	/*TODO Definir las variables miembro
	 * _numKnapsacks Entero que indica el número de mochilas que se va a considerar. Este no se lee del fichero, sino que lo establecéis vosotros
	 * _numObjs Entero donde se almacenará el número de objetos del problema
	 * _flows Matriz donde se van a almacenar los beneficios de los objetos según lo indicado arriba. HAY QUE RESERVAR SU MEMORIA
	 * _weights Vector con los pesos de los objetos. HAY QUE RESERVAR SU MEMORIA
	 * _capacities Vector con las capacidades de las mochilas. HAY QUE RESERVAR SU MEMORIA. Para evitar problemas, reservadlo con capacidad (1 + numKnapsacks) y utilizadlo desde el índice 1 en adelante
	 */
	//int _numKnapsacks;
	int _numFacilities;
	//int* _weights;
	//int* _capacities;
	int _numLocations;
	int** _distances;
	int** _flows;



public:
	/**
	 * Constructor por defecto
	 */
	QAPInstance();

	/**
	 * Destructor
	 */
	~QAPInstance();

	//Cambiada para adaptarla a QAP
	int getNumLocations(){return _numLocations;};
	//int getNumFacility(){return _numLocations;};

	/**
	 * Función de lectura de un fichero de entrada
	 * @param[in] filename Nombre del fichero donde están los datos de la instancia
	 * @param[in] numKnapsacks Entero que indica el número de mochilas que se va a considerar. Este no se lee del fichero, sino que lo establecéis vosotros
	 */
	void readInstance(char *filename);

	//TODO declarar los métodos (y definirlos en QAPInstance.cpp) que devuelvan la información que se consulte acerca de la instancia del problema
	//Entre otros getNumObjs() y getNumKnapsacks()

	/**
	 * Función que devuelve por cuanto se viola la capacidad de la mochila que está más cargada de más
	 * @param[in] solution Referencia a un objeto que representa una solución al problema
	 * @return Máxima violación de las capacidades de las mochilas
	 */
	double getMaxCapacityViolation(QAPSolution &solution);

	/**
	 * Función que calcula la suma de beneficios individuales y cuadráticos de los objetos en mochilas
	 * @param[in] solution Referencia a un objeto que representa una solución al problema
	 * @return Suma de los beneficios individuales y cuadráticos de los objetos en las mochilas
	 */
	double getSumCost(QAPSolution &solution);
};

#endif
