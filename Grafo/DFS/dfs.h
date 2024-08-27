#ifndef DFS_H_
#define DFS_H_
#include <iostream>
#include <list>
#include <utility>

#include "Grafo.h"
using namespace std;

enum ClaseArco
{
    TREE,
    BACK,
    CROSS,
    FORWARD
};

enum Estado
{
    NOVISITADO,
    VISITADO,
    COMPLETO
};

using Arco = std::pair<int, int>;
using ArcoClasificado = std::pair<ClaseArco, Arco>;

/****
 *
 * Clasificación de arcos
 *
 * */
template <class TipoVertice, class TipoArco>
void dfsVisitArcos(Grafo<TipoVertice, TipoArco> *g, int v, std::list<ArcoClasificado> &listaArcos, int &tiempo, Estado *estado, int *descubrimiento)
{

    tiempo++;
    descubrimiento[v] = tiempo;
    estado[v] = VISITADO;

    TipoVertice *adyacentes = g->obtenerAdyacentesPos(v);
    int nAdyacentes = g->getNumAdyacentesPos(v);
    for (int i = 0; i < nAdyacentes; i++)
    {
        int u = g->obtenerPosDelVertice(adyacentes[i]);
        if (estado[u] == NOVISITADO)
        {
            listaArcos.push_back(std::make_pair(TREE, std::make_pair(v, u)));
            dfsVisitArcos(g, u, listaArcos, tiempo, estado, descubrimiento);
        }
        else
        {
            if (estado[u] == VISITADO)
                listaArcos.push_back(std::make_pair(BACK, std::make_pair(v, u)));
            else if (descubrimiento[v] > descubrimiento[u])
                listaArcos.push_back(std::make_pair(CROSS, std::make_pair(v, u)));
            listaArcos.push_back(std::make_pair(FORWARD, std::make_pair(v, u)));
        }
    }

    estado[v] = COMPLETO;
}

template <class TipoVertice, class TipoArco>
void dfsForestArcos(Grafo<TipoVertice, TipoArco> *g)
{

    int numVertices = g->getNumeroVertices();
    list<ArcoClasificado> listaArcos;

    // Estructuras auxiliares
    Estado *estado = new Estado[numVertices];
    int *descubrimiento = new int[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        estado[i] = NOVISITADO;
        descubrimiento[i] = -1;
    }
    int tiempo = 0;

    // Forest
    for (int v = 0; v < numVertices; v++)
    {
        if (estado[v] == NOVISITADO)
            dfsVisitArcos(g, v, listaArcos, tiempo, estado, descubrimiento);
    }

    TipoVertice *vertices = g->obtenerVertices(); // Etiquetas de los vértices
    std::cout << "Referencias\n0: TREE\n1: BACK\n2: CROSS\n3: FORWARD\n\n";
    for (ArcoClasificado par : listaArcos)
    {
        std::cout << "Tipo: " << par.first << ", Arco: " << vertices[par.second.first] << " -> " << vertices[par.second.second] << std::endl;
    }

    delete[] vertices;
    delete[] descubrimiento;
    delete[] estado;
}

/**
 *
 * ** Version con arreglos de descubrimiento y finalización
 *
 * */
template <class TipoVertice, class TipoArco>
void dfsVisitCompleto(Grafo<TipoVertice, TipoArco> *g, int v, int &tiempo, int *padres, Estado *estado, int *descubrimiento, int *finalizacion)
{

    tiempo++;
    descubrimiento[v] = tiempo;
    estado[v] = VISITADO;

    // Recorrido de adyacentes
    TipoVertice *adyacentes = g->obtenerAdyacentesPos(v);
    int nAdyacentes = g->getNumAdyacentesPos(v);
    for (int i = 0; i < nAdyacentes; i++)
    {
        int u = g->obtenerPosDelVertice(adyacentes[i]); // posicion del vertice adyacente a v en la lista de vertices del grafo
        if (estado[u] == NOVISITADO)
        {
            padres[u] = v;
            dfsVisitCompleto(g, u, tiempo, padres, estado, descubrimiento, finalizacion);
        }
    }

    // Finaliza exploración de v
    estado[v] = COMPLETO;
    tiempo++;
    finalizacion[v] = tiempo;
}

template <class TipoVertice, class TipoArco>
void dfsForest(Grafo<TipoVertice, TipoArco> *g)
{
    int numVertices = g->getNumeroVertices();

    // Estructuras auxiliares
    Estado *estado = new Estado[numVertices];
    int *padres = new int[numVertices];
    int *descubrimiento = new int[numVertices];
    int *finalizacion = new int[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        estado[i] = NOVISITADO;
        padres[i] = -1;
        descubrimiento[i] = -1;
        finalizacion[i] = -1;
    }
    int tiempo = 0;

    // Forest
    for (int v = 0; v < numVertices; v++)
    {
        if (estado[v] == NOVISITADO)
            dfsVisitCompleto(g, v, tiempo, padres, estado, descubrimiento, finalizacion);
    }

    // Imprimir resultados

    TipoVertice *vertices = g->obtenerVertices(); // Etiquetas de los vértices
    std::cout << "Vértices:\t";
    for (int i = 0; i < numVertices; i++)
    {
        std::cout << vertices[i] << "  |\t";
    }
    std::cout << "\nPadres:\t\t";
    for (int i = 0; i < numVertices; i++)
    {
        std::cout << vertices[padres[i]] << "  |\t";
    }
    std::cout << "\nDescubrimiento:\t";
    for (int i = 0; i < numVertices; i++)
    {
        std::cout << descubrimiento[i] << "  |\t";
    }
    std::cout << "\nFinalización:\t";
    for (int i = 0; i < numVertices; i++)
    {
        std::cout << finalizacion[i] << "  |\t";
    }
    std::cout << std::endl;

    delete[] finalizacion;
    delete[] descubrimiento;
    delete[] padres;
    delete[] estado;
    delete[] vertices;
}

/***********
 *
 * * Versión solo recorrido *
 *
 * ************ */
template <class TipoVertice, class TipoArco>
void dfsSimple(Grafo<TipoVertice, TipoArco> *g, int v, Estado *estado, int *padres, list<int> &recorrido)
{
    estado[v] = VISITADO;
    recorrido.push_back(v);

    // Recorrido de adyacentes
    TipoVertice *adyacentes = g->obtenerAdyacentesPos(v);
    int nAdyacentes = g->getNumAdyacentesPos(v);
    for (int i = 0; i < nAdyacentes; i++)
    {
        int u = g->obtenerPosDelVertice(adyacentes[i]);
        if (estado[u] == NOVISITADO)
        {
            padres[u] = v;
            dfsSimple(g, u, estado, padres, recorrido);
        }
    }
}

// Orden topologico
template <class TipoVertice, class TipoArco>
void dfsForestSimple(Grafo<TipoVertice, TipoArco> *g)
{
    int numVertices = g->getNumeroVertices();

    // Estructuras auxiliares
    list<int> dfs;
    Estado *estado = new Estado[numVertices];
    int *padres = new int[numVertices];

    for (int i = 0; i < numVertices; i++)
    {
        estado[i] = NOVISITADO;
        padres[i] = -1;
    }

    // Forest
    for (int v = 0; v < numVertices; v++)
    {
        if (estado[v] == NOVISITADO)
            dfsSimple(g, v, estado, padres, dfs);
    }

    // Imprimir resultados
    TipoVertice *vertices = g->obtenerVertices();
    std::cout << "\nRecorrido DFS:\n";
    for (int v : dfs)
    {
        std::cout << vertices[padres[v]] << " -> " << vertices[v] << " \n";
    }

    delete[] padres;
    delete[] estado;
    delete[] vertices;
}
/***********
 *
 * * Versión solo recorrido *
 *
 * ************ */
template <class TipoVertice, class TipoArco>
bool dfsCiclo(Grafo<TipoVertice, TipoArco> *g, int v, Estado *estado)
{
    bool encuentraCiclo = false;
    estado[v] = VISITADO;

    // Recorrido de adyacentes
    TipoVertice *adyacentes = g->obtenerAdyacentesPos(v);
    int nAdyacentes = g->getNumAdyacentesPos(v);
    int i = 0;
    while (!encuentraCiclo && i < nAdyacentes)
    {
        int u = g->obtenerPosDelVertice(adyacentes[i]);
        if (estado[u] == NOVISITADO)
            encuentraCiclo = dfsCiclo(g, u, estado);
        else if (estado[u] == VISITADO)
            encuentraCiclo = true;
        i++;
    }
    estado[v] = COMPLETO;
    return encuentraCiclo;
}

template <class TipoVertice, class TipoArco>
bool hayCicloSimple(Grafo<TipoVertice, TipoArco> *g)
{
    int numVertices = g->getNumeroVertices();
    bool hayCiclo = false;

    Estado *estado = new Estado[numVertices];
    for (int i = 0; i < numVertices; i++)
        estado[i] = NOVISITADO;

    int v = 0;
    while (!hayCiclo && v < numVertices)
    {
        if (estado[v] == NOVISITADO)
            hayCiclo = dfsCiclo(g, v, estado);
        v++;
    }

    delete[] estado;
    return hayCiclo;
}
#endif /* DFS_H_ */
