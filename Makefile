#João Pedro de Oliveira Ventura -- Nº USP 10843503
all: glc
glc: glc.o automato.o
	g++ -o glc automato.o glc.o
automato.o: automato.h automato.cpp
	g++ -c -o automato.o automato.cpp
glc.o: glc.c
	gcc -c -o glc.o glc.c
clean:
	rm glc glc.o automato.o
