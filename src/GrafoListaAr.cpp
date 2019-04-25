#include<iostream>
#include"GrafoListaAr.h"

using namespace std;

GrafoListaAr::GrafoListaAr(int v): Grafo(v){
    if(v > 0){
        this->lista = new int*[v];
        for(int i = 0; i < v; i++)
            this->lista[i] = new int[2];
    }
    else
        this->lista = NULL;
    this->ultimo = 0;
}

GrafoListaAr::~GrafoListaAr() {
    for(int i = 0; i < this->getEdgeNumber(); i++){
        delete [] this->lista[i];
    }
    delete [] this->lista;
}

void GrafoListaAr::inserir(int o, int d) {
    this->lista[this->ultimo][0] = o;
    this->lista[this->ultimo][1] = d;
    this->ultimo++;
    this->setEdgeNumber(this->getEdgeNumber()+1);
    Grafo::inserir(o,d);
}

void GrafoListaAr::imprimir(){
    for(int i = 0; i < this->ultimo; i++){
        cout << "(" << this->lista[i][0] << "," << this->lista[i][1] << "),";
    }
    cout << endl;
}

int GrafoListaAr::faltaCompleto(){return 0;}
int GrafoListaAr::grauVertice(int t){return 0;}
int GrafoListaAr::grau(){return 0;}
void GrafoListaAr::grauMaiorMenorMedia(){}
bool GrafoListaAr::grafoConectado(){return false;}
int GrafoListaAr::buscaLargura(int, int){return 0;}