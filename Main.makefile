all: Grafo.o GrafoListaAdj.o Aresta.o Vertice.o Main.o GrafoMatriz.o
	g++ Grafo.o GrafoListaAdj.o Aresta.o Vertice.o Main.o GrafoMatriz.o -o Main.exe

GrafoMatriz.o: Grafo.h GrafoMatriz.h GrafoMatriz.cpp
	g++ -c GrafoMatriz.cpp

GrafoListaAdj.o: Grafo.h GrafoListaAdj.h GrafoListaAdj.cpp
	g++ -c GrafoListaAdj.cpp

Grafo.o: Grafo.h Grafo.cpp
	g++ -c Grafo.cpp

Aresta.o: Aresta.h Aresta.cpp
	g++ -c Aresta.cpp

Vertice.o: Vertice.h Vertice.cpp
	g++ -c Vertice.cpp

Main.o: Grafo.h Main.cpp
	g++ -c Main.cpp

clean:
	rm *.o
	rm Main.exe
