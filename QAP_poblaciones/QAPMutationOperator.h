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
	 * _numObjs Número de objetos. Se utiliza para reducir el número de consultas a la instancia
	 * _numKnapsacks Número de mochilas del problema. Se utiliza para reducir el número de consultas a la instancia
	 */
	double _mutProb;
	unsigned _numObjs;
	unsigned _numKnapsakcs;

	/**
	 * Función que muta una solución
	 * @param[in,out] sol Solución a mutar
	 */
	void mutate(Solution* sol){
		QAPSolution *s = (QAPSolution*) sol;

		//TODO Recorrer los objetos y, según la probabilidad de mutación,
		//asignarlos a una mochila aleatoria (podrían modificarse 0, 1, o más de 1 gen)

		
		//DUDA Creo que esta bien, tiene sentido

		int i, numero, mochila_aleatoria;
		for (i=0; i<_numObjs; i++)
		{
			numero=(double)(rand())/RAND_MAX;
			if  (numero < _mutProb)
			{
				mochila_aleatoria=rand() % (_numKnapsakcs + 1);
				s->putObjectIn(i, mochila_aleatoria);
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
		_numObjs = instance.getNumObjs();
		_numKnapsakcs = instance.getNumKnapsacks();
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
