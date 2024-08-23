# Grafo

En matemáticas y ciencias de la computación, un grafo (del griego grafos: dibujo, imagen) es un conjunto de objetos llamados vértices o nodos unidos por enlaces llamados aristas o arcos, que permiten representar relaciones binarias entre elementos de un conjunto. Son objeto de estudio de la teoría de grafos. Típicamente, un grafo se representa como un conjunto de puntos (vértices o nodos) unidos por líneas (aristas o arcos).

Desde un punto de vista práctico, los grafos permiten estudiar las interrelaciones entre unidades que interactúan unas con otras. Por ejemplo, una red de computadoras puede representarse y estudiarse mediante un grafo, en el cual los vértices representan terminales y las aristas representan conexiones (las cuales, a su vez, pueden ser cables o conexiones inalámbricas). Prácticamente cualquier problema puede representarse mediante un grafo, y su estudio trasciende a las diversas áreas de las ciencias exactas y las ciencias sociales.

Formalmente un grafo se define como sigue:

G = (V,A)

V: conjunto de vértices no vacío.

A: conjunto de aristas. Cada elemento a de A es un par de vértices (v1;v2) que está en V.

Un **grafo etiquetado** es un grafo G = (V,E) sobre el que se define una función f: A -> E, donde E es un conjunto cuyas componentes se llaman **etiquetas**.

En ocasiones, las _aristas_ pueden tener asociado un **peso**, que muestra el costo de ir de un vértice a otro. Llamamos a esos grafos, **grafos ponderados**. Cuando la arista no tiene un peso asociado, consideraremos que el costo de esa arista es 1.

Ponderación: corresponde a una función que a cada arista le asocia un valor (costo, peso, longitud, etc.), para aumentar la expresividad del modelo. Esto se usa mucho para problemas de optimización, como el del vendedor viajero o del camino más corto.

Grafo No Dirigido

GND = (V,A)

V conjunto de Vertices

V = {A, B, C, D, E, F}

A conjunto de aristas. Cada elemento de A es un par NO ORDENADO de vertices de V

Grafo Dirigido

GD = (V,A)

V conjunto de Vertices

V = {A, B, C, D, E, F}

A conjunto de aristas. Cada elemento de A es un par ORDENADO de vértices de V

