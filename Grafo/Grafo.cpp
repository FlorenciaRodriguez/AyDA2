#include "Grafo.h"
#include <iostream>

template <class TipoVertice, class TipoArco>
Grafo<TipoVertice, TipoArco>::Grafo() {
    this->inicio = nullptr;
    this->nnodos = 0;
}

template <class TipoVertice, class TipoArco>
void Grafo<TipoVertice, TipoArco>::agregarVertice(const TipoVertice & o) {
    Nodo* temp = this->inicio;
    this->inicio = new Nodo;
    inicio->ady = nullptr;
    inicio->sig = temp;
    inicio->etiqueta = o;
    inicio->nodo = nnodos++;
}
/**
template <class TipoVertice, class TipoArco>
void Grafo<TipoVertice, TipoArco>::listar() const {
    Nodo * temp = this->inicio;
    while (temp != nullptr){
        Arco * aux = temp->ady;
        while(aux != nullptr){
            std::cout << temp->etiqueta << "-" << aux->valor << "->" << aux->destino->etiqueta << std::endl;
            aux = aux->sig;
        }
        temp = temp->sig;
    }
}
 */
template <class TipoVertice, class TipoArco>
void Grafo<TipoVertice, TipoArco>::agregarArco(const TipoVertice & o, const TipoVertice & d, const TipoArco & peso){
    Nodo* tempOrigen = this->inicio;
    while (tempOrigen != nullptr && tempOrigen->etiqueta != o){
        tempOrigen = tempOrigen->sig;
    }
    Nodo * tempDestino = this->inicio;
    while (tempDestino != nullptr && tempDestino->etiqueta != d){
        tempDestino = tempDestino->sig;
    }
    if (tempOrigen != nullptr){
        Arco * aux = new Arco;
        aux->valor = peso;
        aux->sig = tempOrigen->ady;
        aux->destino = tempDestino;
        tempOrigen->ady = aux;
    }
}

template <class TipoVertice, class TipoArco>
std::map<int, TipoVertice> Grafo<TipoVertice, TipoArco>::obtenerVertices() const {
    std::map<int, TipoVertice> vertices;
    Nodo *temp = this->inicio;
    while (temp != nullptr) {
        vertices[temp->nodo] = temp->etiqueta;
        temp = temp->sig;
    }
    return vertices;
}

template <class TipoVertice, class TipoArco>
std::map<TipoVertice, TipoArco> Grafo<TipoVertice, TipoArco>::obtenerArcos(const TipoVertice & etiqueta) const {
    std::map<TipoVertice, TipoArco> arcos;
    Nodo *temp = this->inicio;
    
    // Buscar el nodo con la etiqueta dada
    while (temp != nullptr && temp->etiqueta != etiqueta) {
        temp = temp->sig;
    }
    
    // Si el nodo fue encontrado
    if (temp != nullptr) {
        Arco *aux = temp->ady;
        while (aux != nullptr) {
            arcos[aux->destino->etiqueta] = aux->valor;
            aux = aux->sig;
        }
    }
    return arcos;
}

template class Grafo<int, int>;
template class Grafo<char, double>;
template class Grafo<float, float>;
