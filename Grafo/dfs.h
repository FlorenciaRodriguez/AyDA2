#ifndef DFS_H_
#define DFS_H_
#include <iostream>

#include "Grafo.h"
using namespace std;

enum Estado { BLANCO, AMARILLO, NEGRO };
int * padres;
int * descubrimiento;
int * finalizacion;
Estado * estado;
int tiempo;

template <class TipoVertice, class TipoArco>
void dfsVisit(Grafo<TipoVertice, TipoArco>* g,TipoVertice* vertices, int v) {
    
    tiempo++;
    descubrimiento[v] = tiempo;
    estado[v] = AMARILLO;

    TipoVertice* adyacentes = g->obtenerAdyacentes(vertices[v]);
    while (adyacentes!=nullptr) {
        int u = g->obtenerPosDelVertice(*adyacentes); //posicion del vertice en la lista de vertices del grafo
        if (estado[u] == BLANCO) {
            padres[u] = v;
            dfsVisit(g,vertices,u);
        }
        adyacentes++;
    }

    estado[v] = NEGRO;
    tiempo++;
    finalizacion[v] = tiempo;
}

template <class TipoVertice, class TipoArco>
void dfsForest(Grafo<TipoVertice, TipoArco> * g) {
    TipoVertice* vertices = g->obtenerVertices();
    int numVertices = g->getNumeroVertices();
    
    /** Estructuras auxiliares */
    estado=new Estado[numVertices];
    padres=new int[numVertices];
    descubrimiento=new int[numVertices];
    finalizacion=new int[numVertices];
    for (int i=0;i<numVertices;i++){
        estado[i]=BLANCO;
        padres[i]=-1;
        descubrimiento[i]=-1;
        finalizacion[i]=-1;
    }
    tiempo = 0;

    for (int v=0;v<numVertices;v++){
        if (estado[v]==BLANCO)
            dfsVisit(g, vertices, v);
    }
 
    // Imprimir resultados
    std::cout << "Vertices:\t";
    for (int i=0;i<numVertices;i++){
        std::cout << vertices[i] <<"  |\t";
    }
    std::cout << "\nPadres:\t";
    for (int i=0;i<numVertices;i++){
        std::cout << padres[i] <<"  |\t";
    }
    std::cout << "\nDescubrimiento:\t";
    for (int i=0;i<numVertices;i++){
        std::cout << descubrimiento[i] <<"  |\t";
    }
    std::cout << "\nFinalizacion:\t";
    for (int i=0;i<numVertices;i++){
        std::cout << finalizacion[i] <<"  |\t";
    }
};

#endif /* DFS_H_ */