all: glc
glc: glc.o automato.o
	g++ -o glc automato.o glc.o
automato.o: automato.h automato.cpp
	g++ -c -o automato.o automato.cpp
glc.o: glc.cpp
	g++ -c -o glc.o glc.cpp
clean:
	rm glc glc.o automato.o
