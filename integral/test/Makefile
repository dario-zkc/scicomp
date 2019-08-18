CFLAGS = -std=c++17 -O3
CC = g++

functionIntegral: functionIntegral.o integraloperator.o
	$(CC) $(CFLAGS) -o functionIntegral functionIntegral.o integraloperator.o

functionIntegral.o: functionIntegral.cpp
	$(CC) $(CFLAGS) -c functionIntegral.cpp

integraloperator.o: ../integraloperator.cpp
	$(CC) $(CFLAGS) -c ../integraloperator.cpp

clean:
	rm -f functionIntegral *.o
