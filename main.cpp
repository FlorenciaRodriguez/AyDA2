#include <iostream>
#include "Grafo/dfs.h"
using namespace std;

int main(int argc, char **argv)
{
	Grafo<char, int> *g = new Grafo<char, int>;

	g->agregarVertice('a');
	g->agregarVertice('b');
	g->agregarVertice('c');
	g->agregarVertice('d');
    g->agregarVertice('e');
    g->agregarVertice('f');
    g->agregarVertice('h');
    g->agregarVertice('j');
	g->agregarArco('a', 'b', 1);
    g->agregarArco('b', 'c', 2);
    g->agregarArco('d', 'b', 1);
    g->agregarArco('d', 'c', 2);
    g->agregarArco('e', 'd', 3);
    g->agregarArco('f', 'c', 2);
    g->agregarArco('h', 'j', 2);
	dfsForest<char,int>(g);
	return 0;
}

/****
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
};*/