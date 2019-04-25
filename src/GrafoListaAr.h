#ifndef GRAFOLISTAAR_H
#define GRAFOLISTAAr_H
#include"Grafo.h"
class GrafoListaAr: public Grafo {
    private:
        int numeroVertices, ultimo;
        int **lista;
    public:
        GrafoListaAr(int);
        ~GrafoListaAr();

        void imprimir();
        void inserir(int, int);
        int faltaCompleto();
        int grauVertice(int);
        int grau();
        void grauMaiorMenorMedia();
        bool grafoConectado();
        int buscaLargura(int, int);
};
#endif