all: Grafo.o GrafoListaAdj.o Aresta.o Vertice.o Main.o GrafoMatriz.o
	g++ Grafo.o GrafoListaAdj.o Aresta.o Vertice.o Main.o GrafoMatriz.o -o Main.exe

GrafoMatriz.o: src/Grafo.h src/GrafoMatriz.h src/GrafoMatriz.cpp
	g++ -c src/GrafoMatriz.cpp

GrafoListaAdj.o: src/Grafo.h src/GrafoListaAdj.h src/GrafoListaAdj.cpp
	g++ -c src/GrafoListaAdj.cpp

Grafo.o: src/Grafo.h src/Grafo.cpp
	g++ -c src/Grafo.cpp

Aresta.o: src/Aresta.h src/Aresta.cpp
	g++ -c src/Aresta.cpp

Vertice.o: src/Vertice.h src/Vertice.cpp
	g++ -c src/Vertice.cpp

Main.o: src/Grafo.h Main.cpp
	g++ -c Main.cpp

clean:
	rm *.o
	rm Main.exe
