#include <iostream>
#include "Grafo.h"
#include "dfs.h"
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
	g->agregarArco('c', 'e', 1);
	g->agregarArco('d', 'c', 2);
	g->agregarArco('d', 'a', 2);
	g->agregarArco('e', 'd', 3);
	g->agregarArco('c', 'f', 2);
	g->agregarArco('h', 'j', 2);


	return 0;
}
