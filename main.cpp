#include <iostream>
#include "Grafo/Grafo.cpp"
using namespace std;
int main(int argc, char **argv)
{
	Grafo<int, int> *g = new Grafo<int, int>;

	g->agregarVertice(5);
	g->agregarVertice(3);
	g->agregarVertice(2);
	g->agregarVertice(1);
	g->agregarArco(2, 3, 6);
	g->obtenerAdyacentes(2);
	return 0;
};