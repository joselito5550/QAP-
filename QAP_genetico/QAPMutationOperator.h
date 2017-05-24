/*
 * QAPMutationOperator.h
 *
 * Fichero que define la clase QAPMutationOperator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef INCLUDE_QAPMUTATIONOPERATOR_H_
#define INCLUDE_QAPMUTATIONOPERATOR_H_

#include "QAPSolution.h"
#include "Solution.h"
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * Clase que define un operador de mutación para el QAP. Se basa en recorrer todos los genes de la solución y cambiarlos por un valor aleatorio según una probabilidad
 */
class QAPMutationOperator{

protected:
	/**
	 * Variables miembro de la clase
	 * _mutProb Probabilidad de mutación
	 * _numLocalizaciones Número de objetos. Se utiliza para reducir el número de consultas a la instancia
	 * _numInstalaciones Número de mochilas del problema. Se utiliza para reducir el número de consultas a la instancia
	 */
	double _mutProb;
	unsigned _numLocalizaciones;
	unsigned _numInstalaciones;

	/**
	 * Función que muta una solución
	 * @param[in,out] sol Solución a mutar
	 */
	void mutate(Solution* sol){
		QAPSolution *s = (QAPSolution*) sol;
		int pepito=0;
		//TODO Recorrer los objetos y, según la probabilidad de mutación,
		//asignarlos a una mochila aleatoria (podrían modificarse 0, 1, o más de 1 gen)
		for(int i=0;i<_numLocalizaciones/2;i++){
			if(_mutProb>(double)(rand()) / RAND_MAX){//REVISAR probabilidad
				pepito=rand()%(_numInstalaciones);
				s->intercambio(i,pepito);
			}
		}
	}

public:
	/**
	 * Constructor
	 * @param[in] mutProb Probabilidad de mutación
	 * @param[in] instance Instancia del problema a abordar
	 */
	QAPMutationOperator(double mutProb, QAPInstance &instance){
		_mutProb = mutProb;
		_numLocalizaciones = instance.getNumLocations();
		_numInstalaciones = instance.getNumLocations();
	}

	/**
	 * Función que muta un conjunto de soluciones
	 * @param[in,out] sols Soluciones a mutar
	 */
	void mutate(vector<Solution*> &sols){

		for (Solution* sol : sols){
			mutate(sol);
		}
	}
};



#endif /* INCLUDE_QAPMUTATIONOPERATOR_H_ */
