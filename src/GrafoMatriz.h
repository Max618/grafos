#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H
#include"Grafo.h"
class GrafoMatriz: public Grafo{
    private:
        int size, **matriz;

        int** alocaMatriz(int);
        void desalocaMatriz();
    public:
        GrafoMatriz(const int);
        ~GrafoMatriz();

        void inserir(int, int);
        void imprimir();
        int faltaCompleto();
        int grauVertice(int);
        int grau();
        void grauMaiorMenorMedia();
        bool grafoConectado();
        int buscaLargura(int, int);
};
#endif