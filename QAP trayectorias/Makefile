OBJECTS = main.o QAPEvaluator.o QAPGrasp.o QAPInstance.o QAPIteratedGreedy.o  QAPLocalSearch.o QAPObjectAssignmentOperation.o QAPSimpleBestImprovementNO.o QAPSimpleFirstImprovementNO.o QAPSimulatedAnnealing.o QAPSolGenerator.o QAPSolution.o QAPTabuSearch.o Timer.o seeds.o
CPPFLAGS = -c -g -ansi -Wall -std=c++0x 

principal: $(OBJECTS)
	g++ $(OBJECTS) -o principal

main.o: main.cpp seeds.cpp Timer.cpp QAPChangeOperation.h QAPEvaluator.h QAPGrasp.h QAPInstance.h QAPIteratedGreedy.h QAPLocalSearch.h QAPMetaheuristic.h QAPNeighExplorer.h QAPObjectAssignmentOperation.h QAPSolGenerator.h QAPSolution.h  QAPSimpleBestImprovementNO.h QAPSimpleFirstImprovementNO.h  QAPSimulatedAnnealing.h QAPStopCondition.h QAPTabuSearch.h Timer.h
	g++ $(CPPFLAGS) main.cpp 


clean:
	rm -f *.o

