/*
 * QAPCrossoverOperator.h
 *
 * Fichero que define la clase QAPCrossoverOperator. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef INCLUDE_QAPCROSSOVEROPERATOR_H_
#define INCLUDE_QAPCROSSOVEROPERATOR_H_

#include <vector>
 #include <cstdlib>
 
#include "QAPSolution.h"
#include "QAPInstance.h"
#include "QAPGeneticAlgorithm.h"

using namespace std;

/**
 * Clase que implementa un operador de cruce uniforme para el problema QAP. Su idea es la misma que la de un cruce uniforme para codificación entera
 */
class QAPCrossoverOperator {

protected:
	/**
	 * Variables miembro de la clase:
	 *  - _instance Instancia de problema abordada. Se utiliza únicamente para crear nuevos objetos QAPSolution
	 *  - _numLocalizaciones almacena el número de objetos de la instancia abordada para reducir el número de consultas a la instancia
	 *  - _crossProb probabilidad de cruce
	 */
	QAPInstance *_instance;
	unsigned _numLocalizaciones;
	double _crossProb;

	/**
	 * Función que cruza dos soluciones según su probabilidad de cruce. En caso de que no haya crucce, la solución devuelta será igual al primer padre
	 * @param[in] s1 primer padre
	 * @param[in] s2 segundo padre
	 * @return Nuevo objeto solución descendiente de haber cruzado s1 y s2. La solución se reserva dinámicamente en memoria. Es responsabilidad del invocador de gestionarla correctamente.
	 */
	QAPSolution * cross(Solution *s1, Solution *s2) {
		QAPSolution * hijo = new QAPSolution(*_instance);
		QAPSolution * sol1 = (QAPSolution *) s1;
		QAPSolution * sol2 = (QAPSolution *) s2;

		int aux;
		int iterador=0;

		double randSample = (((double) rand()) / RAND_MAX);

		if (randSample < _crossProb) {

			//Rellenamos un 50% del hijo, a partir de 2 particiones del 25% del padre1, una al principio y otra al final esto solo lo leemos nosotros
			for(int i=0;i<_numLocalizaciones/4;i++){
				hijo->putFacility(i, sol1->whereIsFacility(i));
			}
			for(int i=_numLocalizaciones-1; i > (_numLocalizaciones- 1 - _numLocalizaciones/4);i--){
				hijo->putFacility(i, sol1->whereIsFacility(i));
			}

			for(int i=0;i<_numLocalizaciones;i++){
				aux=sol2->whereIsFacility(i);

				if(!hijo->existeIns(aux)){
					hijo->putFacility(iterador+_numLocalizaciones/4, aux);
					iterador+=1;
				}

			}

		} else {
			//Si no hay cruce, copiar el primer padre
			hijo->copy(*sol1);
		}

		return hijo;
	}

public:

	/**
	 * Constructor
	 * @param[in] crossProb Probabilidad de cruce
	 * @param[in] instance Instancia del problema abordada
	 */
	QAPCrossoverOperator(double crossProb, QAPInstance &instance) {
		_instance = &instance;
		_numLocalizaciones = instance.getNumLocations();
		_crossProb = crossProb;
	}

	/**
	 * Función que aplica el cruce a una población de padres.
	 * @param[in] parents Vector de padres. El cruce se aplica entre cada dos padres consecutivos (1,2), (3,4)...
	 * @param[out] offspring Vector donde se almacenan los descendientes generados. IMPORTANTE: Esta función reserva memoria dinámicamente para las nuevas soluciones en offspring, por lo que es responsabilidad de quien la invoque de gestionar la memoria adecuadamente.
	 */
	void cross(vector<Solution*> &parents, vector<Solution*> &offspring) {

		unsigned numParents = (unsigned) parents.size();

		//TODO aplicar cruce entre cada dos padres consecutivos (1,2), (3,4), ...
		for (int i=0;i<numParents;i+=2) {
			QAPSolution *sol = cross(parents[i],parents[i+1]);
			offspring.push_back(sol);
		}
	}
};

#endif /* INCLUDE_QAPCROSSOVEROPERATOR_H_ */
