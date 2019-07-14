CFLAGS = -std=c++17
CC = g++

functionDerivative: functionDerivative.o derivativeoperator.o
	$(CC) $(CFLAGS) -o functionDerivative functionDerivative.o derivativeoperator.o

functionDerivative.o: functionDerivative.cpp
	$(CC) $(CFLAGS) -c functionDerivative.cpp

derivativeoperator.o: derivativeoperator.cpp
	$(CC) $(CFLAGS) -c derivativeoperator.cpp

clean:
	rm -f functionDerivative *.o
