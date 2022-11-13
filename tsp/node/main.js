const Grafo = require('./grafo.js');

var g = new Grafo(4);

g.addAresta(0, 1, 4);
g.addAresta(0, 2, 5);
g.addAresta(0, 3, 3);
g.addAresta(1, 2, 3);
g.addAresta(1, 3, 5);
g.addAresta(2, 3, 4);

g.tsp(0);