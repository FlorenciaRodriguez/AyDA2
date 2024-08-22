#include <iostream>
#include "Grafo/Grafo.cpp"
using namespace std;
int main(int argc, char **argv)
{
	Grafo<int>* g = new Grafo<int>;
	g->agregarVertice(1);
	g->agregarVertice(2);
	g->agregarVertice(3);
	g->agregarVertice(4);
	g->agregarVertice(5);
    g->agregarArco(2,3,6);
    cout << "Estructura del GrafoDirigido: " << endl;
   g->listar();
    return 0;
};