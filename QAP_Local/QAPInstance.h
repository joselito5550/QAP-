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

#include <vector>
using namespace std;

/**
 * Clase que almacena la información de una instancia del problema QAP
 */
class QAPInstance {
protected:
	/*Definir las variables miembro
	 * _numKnapsacks Entero que indica el número de mochilas que se va a considerar. Este no se lee del fichero, sino que lo establecéis vosotros
	 * _numObjs Entero donde se almacenará el número de objetos del problema
	 * _profits Matriz donde se van a almacenar los beneficios de los objetos según lo indicado arriba. HAY QUE RESERVAR SU MEMORIA
	 * _weights Vector con los pesos de los objetos. HAY QUE RESERVAR SU MEMORIA
	 * _capacities Vector con las capacidades de las mochilas. HAY QUE RESERVAR SU MEMORIA. Para evitar problemas, reservadlo con capacidad (1 + numKnapsacks) y utilizadlo desde el índice 1 en adelante
	 */

	int _numFacilities;
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

	/**
	 * Función de lectura de un fichero de entrada
	 * @param[in] filename Nombre del fichero donde están los datos de la instancia
	 * @param[in] numKnapsacks Entero que indica el número de mochilas que se va a considerar. Este no se lee del fichero, sino que lo establecéis vosotros
	 */
	void readInstance(char *filename);

	/**
	 * Funciones getter que devuelven la información que se consulte acerca de la instancia del problema
	 */

	int getNumLocations(){return _numLocations;};

	double getFlow(int i, int j){return _flows[i][j];}

	double getDistance(int o1, int o2){return _distances[o1][o2];}



	/**
	 * Función que calcula la suma de costes de todos lo edificios asignados
	 * @param[in] solution Referencia a un objeto que representa una solución al problema
	 * @return Suma de los costes de asignacion
	 */
	double getSumCost(QAPSolution &solution);

	/**
	 * Función que genera una permutación de los enteros de 0 a (size - 1)
	 * @param[in] size Tamaño de la permutación
	 * @param[out] perm Vector donde se almacenará la permutación
	 */
	static void randomPermutation(int size, vector<int> &perm);

	/**
	 * Función que calcula la diferencia en la suma de los beneficios si a la solución se le aplicase la asignación del objeto indexObject a la mochila indexKnapsack
	 * @param[in] solution Referencia a un objeto que representa una solución al problema.
	 * @param[in] indexFacility1 Índice del edificio que se pondría en otra localización
	 * @param[in] indexFacility2 Índice de la localización donde se pondrá el edificio
	 * @return Diferencia ede costes al realizar una nueva asignación
	 *
	 */
	double getDeltaSumCost(QAPSolution &solution, int indexFacility1, int indexFacility2);

};

#endif

