#ifndef GRAFO_H_
#define GRAFO_H_

#include <map>
#include <vector>

template <typename T, typename C>
class Grafo
{
private:
    struct Arco;
    struct Nodo
    {
        T etiqueta;
        int nodo;
        Nodo *sig;
        Arco *ady;
    };
    
    struct Arco
    {
        C valor;
        Arco *sig;
        Nodo *destino;
    };
    
    Nodo *inicio;
    int nnodos;
public:
    Grafo();
    void agregarVertice(const T & dato);
    //void listar() const;
    void agregarArco(const T & o,const T & d, const C & peso);
    std::map<int, T> obtenerVertices() const;
    std::map<T, C> obtenerArcos(const T & etiqueta) const;
};

#endif /* GRAFO_H_ */
