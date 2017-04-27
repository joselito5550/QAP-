OBJECTS = main.o MQKPEvaluator.o MQKPGrasp.o MQKPInstance.o MQKPIteratedGreedy.o  MQKPLocalSearch.o MQKPObjectAssignmentOperation.o MQKPSimpleBestImprovementNO.o MQKPSimpleFirstImprovementNO.o MQKPSimulatedAnnealing.o MQKPSolGenerator.o MQKPSolution.o MQKPTabuSearch.o Timer.o seeds.o
CPPFLAGS = -c -g -ansi -Wall -std=c++0x 

principal: $(OBJECTS)
	g++ $(OBJECTS) -o principal

main.o: main.cpp seeds.cpp Timer.cpp MQKPChangeOperation.h MQKPEvaluator.h MQKPGrasp.h MQKPInstance.h MQKPIteratedGreedy.h MQKPLocalSearch.h MQKPMetaheuristic.h MQKPNeighExplorer.h MQKPObjectAssignmentOperation.h MQKPSolGenerator.h MQKPSolution.h  MQKPSimpleBestImprovementNO.h MQKPSimpleFirstImprovementNO.h  MQKPSimulatedAnnealing.h MQKPStopCondition.h MQKPTabuSearch.h Timer.h
	g++ $(CPPFLAGS) main.cpp 


clean:
	rm -f *.o

