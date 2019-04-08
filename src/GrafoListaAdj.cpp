#include"GrafoListaAdj.h"
#include"Vertice.h"
#include"Aresta.h"
#include<iostream>
#include<string>

using namespace std;

GrafoListaAdj::GrafoListaAdj(int v): Grafo(v){
    if(v > 0){
        this->list = new Vertice[v];
    }
    else {
        this->list = NULL;
    }
}

GrafoListaAdj::~GrafoListaAdj(){
    //cout << "Destrutor Grafo...\n";
    delete [] this->list;
}

int GrafoListaAdj::linhaVazia(int l){
    return (this->list[l].getInicio() == NULL);
}

void GrafoListaAdj::inserir(int s, int c){
    //if(s != c){
        Aresta *nova = new Aresta(0,c);
        this->list[s].inserirOrdenado(nova,s);
    //}
    Grafo::inserir(s,c);
}

Vertice* GrafoListaAdj::getList(){
    return this->list;
}

void GrafoListaAdj::imprimir(){
    cout << "[Origem] -> [Destino|Peso]" << endl;
    for(int i = 0; i < this->getVertexNumber(); i++){
        cout << "[" << i << "]: ";
        this->list[i].getInicio()->imprime();
        cout << endl << endl;
    }
}

int GrafoListaAdj::faltaCompleto(){
    return ((this->getVertexNumber()*(this->getVertexNumber()-1))/2) - this->getEdgeNumber();
}

int GrafoListaAdj::grauVertice(int v){
    return 0;
}

int GrafoListaAdj::grau() {
    return 2*this->getEdgeNumber();
}

void GrafoListaAdj::grauMaiorMenorMedia(){}
bool GrafoListaAdj::grafoConectado(){return false;}