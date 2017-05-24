/*
 * QAPSolGenerator.cpp
 *
 * Fichero que define los métodos de la clase QAPInstance. Forma parte del código esqueleto para el problema de las múltiples mochilas cuadráticas, ofrecido para las prácticas de la asignatura Metaheurísticas del Grado de Ingeniería Informática de la Universidad de Córdoba
 *
 * @author Carlos García cgarcia@uco.es
 */

#include "QAPSolGenerator.h"
#include "QAPInstance.h"
#include "QAPSolution.h"
#include <stdlib.h>
 #include <iostream>

void QAPSolGenerator::genRandomSol(QAPInstance &instance, QAPSolution &solution){

	int numLoc = instance.getNumLoc();

	solution.clear();

	for (int l = 0; l < numLoc; l++){
		int instalacionAleatoria = rand() % numLoc;

		if(!solution.existeIns(instalacionAleatoria))
			solution.putInstalacion(instalacionAleatoria, l);
		
		else
			l--;
	}
}