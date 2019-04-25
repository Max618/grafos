#include"GrafoListaAdj.h"
#include"Vertice.h"
#include"Aresta.h"
#include"Fila.cpp"
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

int GrafoListaAdj::buscaLargura(int saida, int chegada){

    if(saida == chegada) return 0;

    Fila <int> Q(999);
    Aresta *aux = NULL;
    int v;
    Q.inserir(saida);
    this->list[saida].setCor('p');

    while(!Q.vazia())                                               //ENQUANTO A FILA NAO ESTIVER VAZIA
    {
        v = Q.remover();                                            //PEGO O PRIMEIRO DA FILA
        aux = this->list[v].getInicio();                            

        while(aux != NULL)                                          //PASSO POR TODOS SEUS ADJACENTES
        {
            if(this->list[aux->getChegada()].getCor() == 'b')       //SE ELE AINDA NAO FOI VISITADO
            {
                Q.inserir(aux->getChegada());                       //COLOCO NA FILA
            }
            aux = aux->getProx();
            
        }

        this->list[v].setCor('p');                                  //MARCO O VERTICE COMO VISITADO
    }

    return 0;
}

void GrafoListaAdj::grauMaiorMenorMedia(){}
bool GrafoListaAdj::grafoConectado(){return false;}