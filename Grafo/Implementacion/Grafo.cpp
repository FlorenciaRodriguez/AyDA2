#include "Grafo.h"
#include <iostream>
#include <cassert>
template <class TipoVertice, class TipoArco>

Grafo<TipoVertice, TipoArco>::Grafo()
{
    this->inicio = nullptr;
    this->nnodos = 0;
}
template <class TipoVertice, class TipoArco>
Grafo<TipoVertice, TipoArco>::~Grafo() {
    Nodo *tempNodo = inicio;
    while (tempNodo != nullptr) {
        Arco *tempArco = tempNodo->ady;
        while (tempArco != nullptr) {
            Arco *arcoAEliminar = tempArco;
            tempArco = tempArco->sig;
            delete arcoAEliminar;
        }
        
        Nodo *nodoAEliminar = tempNodo;
        tempNodo = tempNodo->sig;
        delete nodoAEliminar;
    }
}

template <class TipoVertice, class TipoArco>
void Grafo<TipoVertice, TipoArco>::agregarVertice(const TipoVertice &o)
{

    bool existeVertice = false;

    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->ady = nullptr;
    nuevoNodo->sig = nullptr;
    nuevoNodo->etiqueta = o;
    nuevoNodo->incidencias = 0;
    nuevoNodo->adyacencias = 0;

    if (this->inicio == nullptr)
    {
        this->inicio = nuevoNodo;
    }
    else
    {
        Nodo *temp = this->inicio;
        while (temp->sig != nullptr && !existeVertice)
        {
            if (temp->etiqueta == o)
            {
                existeVertice = true;
            }

            temp = temp->sig;
        }
        assert(!existeVertice);
        temp->sig = nuevoNodo;
    }
    this->nnodos += 1;
}

template <class TipoVertice, class TipoArco>
void Grafo<TipoVertice, TipoArco>::agregarArco(const TipoVertice &o, const TipoVertice &d, const TipoArco &peso)
{
    // Buscar el nodo origen
    Nodo *tempOrigen = this->inicio;
    while (tempOrigen != nullptr && tempOrigen->etiqueta != o)
    {
        tempOrigen = tempOrigen->sig;
    }
    assert(tempOrigen != nullptr && tempOrigen->etiqueta == o);

    // Buscar el nodo destino
    Nodo *tempDestino = this->inicio;
    while (tempDestino != nullptr && tempDestino->etiqueta != d)
    {
        tempDestino = tempDestino->sig;
    }
    assert(tempDestino != nullptr && tempDestino->etiqueta == d);

    // Verificar si ya existe un arco entre o y d
    Arco *aux = tempOrigen->ady;
    bool existeArco = false;
    while (aux != nullptr && !existeArco)
    {
        if (aux->destino->etiqueta == d)
            existeArco = true;
        aux = aux->sig;
    }
    
    assert(!existeArco);

    Arco *nuevoArco = new Arco;
    nuevoArco->valor = peso;
    nuevoArco->destino = tempDestino;
    nuevoArco->sig = nullptr;

    // Insertar el arco al final de la lista de adyacencias
    if (tempOrigen->ady == nullptr)
        tempOrigen->ady = nuevoArco;
    else
    {
        nuevoArco->sig = tempOrigen->ady;
        tempOrigen->ady = nuevoArco;
    }
    tempOrigen->adyacencias += 1;
    tempDestino->incidencias += 1;
}

template <class TipoVertice, class TipoArco>
TipoVertice *Grafo<TipoVertice, TipoArco>::obtenerVertices() const
{
    TipoVertice *vertices = new TipoVertice[this->nnodos];
    int i = 0;
    Nodo *temp = this->inicio;
    while (temp != nullptr)
    {
        vertices[i] = temp->etiqueta;
        temp = temp->sig;
        i += 1;
    }

    return vertices;
}

template <class TipoVertice, class TipoArco>
int Grafo<TipoVertice, TipoArco>:: getNumeroVertices() const{
    return this->nnodos;
}

template <class TipoVertice, class TipoArco>
int Grafo<TipoVertice, TipoArco>::obtenerPosDelVertice(const TipoVertice &etiqueta) const{
   Nodo*temp = this->inicio;
   int posVertice=0;
   while (temp!=nullptr && temp->etiqueta!=etiqueta){
    
    temp=temp->sig;
    posVertice+=1;
   }
   assert(temp!=nullptr && temp->etiqueta==etiqueta);
   return posVertice;

}

template <class TipoVertice, class TipoArco>
int  Grafo<TipoVertice, TipoArco>::getNumAdyacentes(const TipoVertice &etiqueta) const
{
    Nodo*temp = this->inicio;
    while (temp!=nullptr && temp->etiqueta!=etiqueta)
        temp=temp->sig;
    assert(temp!=nullptr && temp->etiqueta==etiqueta);
    return temp->adyacencias;
}

template <class TipoVertice, class TipoArco>
TipoVertice *Grafo<TipoVertice, TipoArco>::obtenerAdyacentes(const TipoVertice &etiqueta) const
{

    Nodo *temp = this->inicio;
    while (temp != nullptr && temp->etiqueta != etiqueta)
    {
        temp = temp->sig;
    }

    if (temp != nullptr && temp->adyacencias>0)
    {
        TipoVertice *arcos = new TipoVertice[temp->adyacencias];
        int i = 0;
        Arco *aux = temp->ady;
        while (aux != nullptr)
        {
            arcos[i] = aux->destino->etiqueta;
            aux = aux->sig;
            i++;
            
        }
        return arcos;
    }
    else
    {
        return nullptr;
    }
}

template class Grafo<int, int>;
template class Grafo<char, double>;
template class Grafo<char, int>;
template class Grafo<float, float>;
