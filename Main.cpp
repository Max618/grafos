#include<iostream>
#include"GrafoMatriz.h"
#include"GrafoListaAdj.h"
#include"Grafo.h"
void lerArquivo(Grafo **grafo){
    int n1,n2;
    char c,c2;
    FILE *file = fopen("erdos.edgelist","r");
    while(!feof(file)){
        fscanf(file, "%d %d %c%c",&n1,&n2, &c, &c2);
        grafo[0]->inserir(n1,n2);
        grafo[1]->inserir(n1,n2);
    }
}

int main() {
    Grafo *grafo[3];
    grafo[0] = new GrafoMatriz(1000);
    grafo[1] = new GrafoListaAdj(1000);
    lerArquivo(grafo);
    grafo[0]->imprimir();
    system("sleep 3");
    grafo[1]->imprimir();

    cout << "Numero vertices Matriz: " << grafo[0]->getEdgeNumber() << endl;
    cout << "Numero vertices Lista Adj: " << grafo[1]->getEdgeNumber() << endl;
    return 0;
}