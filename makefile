proj3: main.o hex.o Registers.o
	g++ main.o hex.o Registers.o -o proj3

main.o: main.cpp hex.h 
	g++ -c main.cpp

hex.o: hex.cpp hex.h
	g++ -c hex.cpp

Registers.o: Registers.h Registers.cpp
	g++ -c Registers.cpp

clean:
	rm *.o proj3

