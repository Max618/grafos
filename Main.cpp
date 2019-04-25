#include<iostream>
#include"src/GrafoMatriz.h"
#include"src/GrafoListaAdj.h"
#include"src/GrafoListaAr.h"
#include"src/Grafo.h"
void lerArquivo(Grafo **grafo){
    int n1,n2;
    char c,c2;
    FILE *file = fopen("erdos.edgelist","r");
    while(!feof(file)){
        fscanf(file, "%d %d %c%c",&n1,&n2, &c, &c2);
        grafo[0]->inserir(n1,n2);
        grafo[1]->inserir(n1,n2);
        grafo[2]->inserir(n1,n2);
    }
}

int main() {
    Grafo *grafo[3];
    int n, v = 0;
    bool b = true;
    grafo[0] = new GrafoMatriz(1000);
    grafo[1] = new GrafoListaAdj(1000);
    grafo[2] = new GrafoListaAr(75085);
    lerArquivo(grafo);
    
    while(b) {
        cout << "0 - Sair" << endl;
        cout << "Escolha 1 opcao:" << endl;
        cout << "1 - Imprimir Matriz" << endl;
        cout << "2 - Imprimir Lista Adj" << endl;
        cout << "3 - Imprimir Lista arestas" << endl;
        cout << "4 - Exibir numero de arestas" << endl;
        cout << "5 - Exibir numero de vertices" << endl;
        cout << "6 - Exibir complemento para o grafo ser completo" << endl;
        cout << "7 - Verificar se o grafo é euleriano" << endl;
        cout << "8 - Exibir o grau de um vertice" << endl;
        cout << "9 - Exibir a soma dos graus do vertices" << endl;
        cout << "10 - Exibir maior, menor e grau medio" << endl;
        cout << "11 - Verificar se grafo é conectado" << endl;
        cout << "12 - Busca em Largura" << endl;

        cin >> n;
        switch(n) {
            case 0:
                b = false;
            break;
            case 1:
                grafo[0]->imprimir();
            break;
            case 2:
                grafo[1]->imprimir();
            break;
            case 3:
                grafo[2]->imprimir();
            break;
            case 4:
                cout << "Numero de arestas: " << grafo[0]->getEdgeNumber() << endl;
            break;
            case 5: 
                cout << "Numero de vertices: " << grafo[0]->getVertexNumber() << endl;
            break;
            case 6:
                cout << "Complemento para ser um grafo completo: " << grafo[0]->faltaCompleto() << endl;
            break;
            case 7:
                cout << "Estamos construindo ainda..." << endl;
            break;
            case 8:
                cout << "Vertice que deseja (0 - 999): ";
                cin >> v;
                cout << "Grau do vertice " << v << ": " << grafo[0]->grauVertice(v) << endl;
            break;
            case 9:
                cout << "Grau grafo: " << grafo[0]->grau() << endl;
            break;
            case 10:
                grafo[0]->grauMaiorMenorMedia();
            break;
            case 11:
                if(grafo[0]->grafoConectado())
                    cout << "O grafo é conectado" << endl;
                else
                    cout << "O grafo não é conectado" << endl;
            break;
            case 12:
                grafo[1]->buscaLargura(1, 10);
            break;
        }
        //system("sleep 2");
    }
    return 0;
}