#ifndef GRAFOLISTAADJ_H
#define GRAFOLISTAADJ_H
#include"Grafo.h"
#include"Vertice.h"
class GrafoListaAdj: public Grafo {
    private:
        Vertice *list;
        int linhaVazia(int);
    public:
        GrafoListaAdj(int);
        ~GrafoListaAdj();

        void imprimir();
        void inserir(int, int);
        int faltaCompleto();
        int grauVertice(int);
        int grau();
        void grauMaiorMenorMedia();
        bool grafoConectado();
        int buscaLargura(int, int);

        Vertice* getList();
};
#endif