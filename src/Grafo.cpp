#include<iostream>
#include"Grafo.h"

using namespace std;

Grafo::Grafo(int v){
    this->vertex_number = v;
    this->edge_number = 0;
}

Grafo::~Grafo() {

}

int Grafo::getVertexNumber() {
    return this->vertex_number;
}

int Grafo::getEdgeNumber() {
    return this->edge_number;
}

void Grafo::setEdgeNumber(int e) {
    this->edge_number = e;
}

void Grafo::setVertexNumber(int v) {
    this->vertex_number = v;
}

void Grafo::inserir(int s, int c) {
    this->edge_number++;
}