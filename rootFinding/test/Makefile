CFLAGS = -std=c++17 -O3 -I /home/dario/repo/scicomp
CC = g++

functionRoot: functionRoot.o rootfinder.o derivativeoperator.o
	$(CC) $(CFLAGS) -o functionRoot functionRoot.o rootfinder.o derivativeoperator.o

functionRoot.o: functionRoot.cpp
	$(CC) $(CFLAGS) -c functionRoot.cpp

rootfinder.o: ../rootfinder.cpp
	$(CC) $(CFLAGS) -c ../rootfinder.cpp

derivativeoperator.o: ../../derivative/derivativeoperator.cpp
	$(CC) $(CFLAGS) -c ../../derivative/derivativeoperator.cpp

clean:
	rm -f functionRoot *.o
