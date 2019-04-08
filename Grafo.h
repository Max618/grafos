#ifndef GRAFO_H
#define GRAFO_H
class Grafo {
    private:
        int vertex_number, edge_number;
    public:
        int getVertexNumber();
        int getEdgeNumber();
        void setVertexNumber(int);
        void setEdgeNumber(int);
    
        virtual void inserir(int, int) = 0;
        virtual void imprimir() = 0;
        virtual ~Grafo();
        Grafo(int);
};
#endif