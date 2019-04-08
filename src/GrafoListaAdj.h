#ifndef GRAFOLISTAADJ_H
#define GRAFOLISTAADJ_H
#include"Grafo.h"
#include"Vertice.h"
class GrafoListaAdj: public Grafo {
    private:
        int numeroVertices;
        Vertice *list;
        int linhaVazia(int);
    public:
        GrafoListaAdj(int);
        ~GrafoListaAdj();

        void imprimir();
        void inserir(int, int);

        Vertice* getList();
};
#endif