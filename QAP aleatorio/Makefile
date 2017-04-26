OBJECTS = main.o QAPEvaluator.o QAPInstance.o QAPSolGenerator.o QAPSolution.o Timer.o seeds.o
CPPFLAGS = -c -g -ansi -Wall -std=c++0x

principal: $(OBJECTS)
	g++ $(OBJECTS) -o principal 

main.o: main.cpp seeds.cpp QAPEvaluator.h QAPInstance.h QAPSolGenerator.h QAPSolution.h Timer.h
	g++ $(CPPFLAGS) main.cpp 


clean:
	rm -f *.o

