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

    //IMPRIMIR EM FORMA DE MATRIZ
    /*
    for(int i = 0; i < this->size; i++)
        printf(" %d |", i);

    for(int i = 0; i < this->size; i++){
        for(int k = 0; k < 168; k++)
            printf("-");
        printf("\n");
        printf("%d: ",i);
        for(int j = 0; j < this->size; j++){
            //if(this->matriz[i][j] != 0){
                printf(" %d |",this->matriz[i][j]);
            //}
        }
        printf("\n");
    }
    for(int k = 0; k < 168; k++)
        printf("-");
    printf("\n");*/
}

int GrafoMatriz::faltaCompleto(){
    return ((this->getVertexNumber()*(this->getVertexNumber()-1))/2) - this->getEdgeNumber();
}

int GrafoMatriz::grauVertice(int v){
    int c = 0;
    for(int i = 0; i < this->getVertexNumber(); i++)
        c+= this->matriz[v][i] + this->matriz[i][v];
    return c;
}

int GrafoMatriz::grau() {
    return 2*this->getEdgeNumber();
}

void GrafoMatriz::grauMaiorMenorMedia() {
    int maior, menor, temp;
    maior = menor = this->grauVertice(0);
    for(int i = 1; i < this->getVertexNumber(); i++){
        temp = this->grauVertice(i);
        if(temp > maior)
            maior = temp;
        else if(temp < menor)
            menor = temp;
    }
    cout << "Maior grau: " << maior << endl;
    cout << "Menor grau: " << menor << endl;
    cout << "Grau medio: " << 2*this->getEdgeNumber()/this->getVertexNumber() << endl;
}

bool GrafoMatriz::grafoConectado() {
    for(int i = 1; i < this->getVertexNumber(); i++) {
        for(int j = 0; j < this->getVertexNumber(); j ++) {
            if(this->matriz[i][j] == 1 || this->matriz[i][j] == 1)
                continue;
            return false;
        }
    }
    return true;
}