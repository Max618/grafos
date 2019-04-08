#include"GrafoMatriz.h"
#include<iostream>
#include"Grafo.h"
using namespace std;

GrafoMatriz::GrafoMatriz(const int size): Grafo(size){
    this->size = size;
    this->matriz = this->alocaMatriz(size);
}

GrafoMatriz::~GrafoMatriz() {
    this->desalocaMatriz();
}

int** GrafoMatriz::alocaMatriz(int size){
    int **matriz = new int*[size];
    for(int i = 0; i < size; i++)
        matriz[i] = new int[size];
    return matriz;
}

void GrafoMatriz::desalocaMatriz(){
    for(int i = 0; i < this->size; i++)
        delete [] this->matriz[i];
    delete [] this->matriz;
}

void GrafoMatriz::inserir(int origin, int destiny){
    this->matriz[origin][destiny] = 1;
    Grafo::inserir(origin, destiny);
}

void GrafoMatriz::imprimir() {
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size; j++){
            if(this->matriz[i][j] != 0){
                printf("[%d|%d] -> %d\n",i,j,this->matriz[i][j]);
            }
        }
    }
}