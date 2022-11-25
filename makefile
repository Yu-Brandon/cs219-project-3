proj2: main.o hex.o
	g++ main.o hex.o -o proj2

main.o: main.cpp hex.h 
	g++ -c main.cpp

hex.o: hex.cpp hex.h
	g++ -c hex.cpp

clean:
	rm *.o proj1

