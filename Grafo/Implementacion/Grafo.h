#ifndef GRAFO_H_
#define GRAFO_H_

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
        int incidencias;
        int adyacencias;
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
    ~Grafo();
    void agregarVertice(const T &dato);
    void agregarArco(const T &o, const T &d, const C &peso);
    T *obtenerVertices() const;
    T *obtenerAdyacentes(const T &etiqueta) const;
    int obtenerPosDelVertice(const T &etiqueta) const;
    int getNumeroVertices() const;
    int getNumAdyacentes(const T &etiqueta) const;
};

#endif /* GRAFO_H_ */
