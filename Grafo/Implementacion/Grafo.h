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
    int nVertices;
    int nArcos;
    int grado;

public:
    Grafo();
    ~Grafo();
    void agregarVertice(const T &dato);
    void agregarArco(const T &o, const T &d, const C &peso);
    int getGrado() const;
    int getGradoVertice(const T &etiqueta) const;
    T *obtenerVertices() const;
    T *obtenerAdyacentes(const T &etiqueta) const;
    T *obtenerAdyacentesPos(int pos) const;
    int obtenerPosDelVertice(const T &etiqueta) const;
    int getNumeroVertices() const;
    int getNumAdyacentes(const T &etiqueta) const;
    int getNumAdyacentesPos(int pos) const;
};

#endif /* GRAFO_H_ */
