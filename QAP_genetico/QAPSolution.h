 /**
 * QAPSolution.h
 * 
 * Fichero que define la clase QAPSolution. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef __QAPSOLUTION_H__
#define __QAPSOLUTION_H__

#ifndef __QAPINSTANCE_H__
#include "QAPInstance.h"
#else
class QAPInstance;
#endif

#include "Solution.h"

/**
 * Clase que representa una solución al problema
 *
 * Sobre la representación de soluciones:
 * La representación de las soluciones será un vector de número enteros: de 1 a M para objetos que están en alguna de las M mochilas y 0 para objetos que no están en ninguna mochilas
 */
#include <vector>
using namespace std;
using std::vector;

class QAPSolution : public Solution {
protected:
	/* Definir las variables miembro
	 * _sol Vector de enteros que será la representación interna de la solución al problema
	 * _numLocalizaciones Entero donde se almacenará el número de localizaciones del problema
	 * _fitness valor double que almacena la calidad de la solución
	 */
	int * _sol;
	int _numLocalizaciones;
	double _fitness;
	bool _fitnessAssigned;

public:
	/**
	 * Constructor
	 * @param[in] instance Referencia a un objeto con la información de la instancia del problema QAP
	 */
	QAPSolution(QAPInstance &instance);

	/**
	 * Destructor
	 */
	~QAPSolution();

	/**
	 * Función que asigna un objeto a la mochila indicada
	 * @param[in] object Índice del objeto a insertar en la mochila indicada
	 * @param[in] knapsack Índice de la mochila donde insertar el objeto
	 */
	void putInstalacion(int instalacion, int localizacion);

	/**
	 * Función que devuelve la mochila en la que está insertado un objeto
	 * @param[in] object Índice del objeto consultado
	 * @return Índice de la mochila en la que está insertado el objeto
	 */
	int whereIsInstalacion(int instalacion);

	/**
	 *Función añadida que nos dice qué instalación hay en una localización pasada como parámetro
	 */

	int whatIsInLocalizacion(int localizacion);

	/**
	 * Función que devuelve el fitness de la solución
	 *
	 * @return fitness de la solución
	 */
	double getFitness() const;

	/**
	 * Función que asigna el fitness de la solución
	 * @param[in] fitness Fitness de la solución
	 */
	void setFitness(double fitness);

	/**
	 * Función que copia la información de otra solución
	 * @param[in] solution La solución de donde copiar la información
	 */
	void copy(Solution &solution);

	/*
	 * Función auxiliar para intercambiar dos instalaciones en el vector solución
	*/
	void intercambio(int &l1, int &l2);

	inline void clear(){
		for(int l = 0; l < _numLocalizaciones; l++)
			putInstalacion(-1,l);
	}

	bool existeIns(int ins);

	bool hasValidFitness(){
		return _fitnessAssigned;
	}
};

#endif