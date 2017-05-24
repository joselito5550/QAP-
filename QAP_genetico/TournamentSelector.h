/*
 * TournamentSelector.h
 *
 * Fichero que define la clase QAPTournamentSelector. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#ifndef INCLUDE_TOURNAMENTSELECTOR_H_
#define INCLUDE_TOURNAMENTSELECTOR_H_

#include <vector>
#include <cstdlib>

#include "Solution.h"
#include "SelectionOperator.h"

using namespace std;

/**
 * Clase que implementa el operador de selección por torneo
 */
class TournamentSelector : public SelectionOperator{

protected:
	/**
	 * Variables miembro de la clase
	 * _k número de participantes en el torneo
	 */
	unsigned _k;

	/**
	 * Función que selecciona una solución del conjunto mediante torneo
	 * @param[in] set Vector de soluciones
	 * @result Solución seleccionada
	 */
	Solution* selectOne (vector<Solution*> &set){

		/**
		 * TODO
		 * 1. Seleccionar una solución aleatoria como la actualmente ganadora
		 *
		 * 2. Repetir (_k-1) veces la selección de otra solución aleatoria y el torneo con la actualmente ganadora (mantener la mejor)
		 */

		 Solution * best;
		 int actualGanadora;
		 int iterador=0;

		 //actualGanadora=set[rand()%set.size()];

		 actualGanadora=0;//Inicializamos al elemento 0 como actual ganadora

		 for(int i=0;i<_k-1;i++){
		 	iterador=rand()%set.size();
		 	if(set[iterador]->getFitness() < set[actualGanadora]->getFitness()){
		 		actualGanadora=iterador;
		 	} 
		 }

		best=set[actualGanadora];//REVISAR si debemos asignar mediante copy

		return best;
	}

public:

	/**
	 * Constructor
	 * @param[in] k Número de participantes en el torneo
	 */
	TournamentSelector(unsigned k){
		_k = k;
	}

	/**
	 * Destructor
	 */
	virtual ~TournamentSelector(){}

	/**
	 * Función que selecciona tantas parejas de padres de un vector como elementos hay en dicho vector
	 * @param[in] orig Vector de soluciones sobre el que aplicar la selección
	 * @param[out] result Vector donde se almacenan las parejas de padres seleccionadas
	 */
	virtual void select(vector<Solution*> &orig, vector<Solution*> &result){

		//TODO utilizando le método propio selectOne, seleccionar tantas parejas
		//de padres como elementos hay en orig
		

		for(int i=0;i<orig.size();i++){
			result.push_back(selectOne(orig));//Primer miembro de pareja
			result.push_back(selectOne(orig));//Segundo miembro de pareja
		}
	}
};



#endif /* INCLUDE_TOURNAMENTSELECTOR_H_ */