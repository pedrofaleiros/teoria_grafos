const Grafo = require("./grafo.js");

var g = new Grafo(12);

g.addAresta(0  ,1 , 3162);
g.addAresta(0  ,2 , 2828);
g.addAresta(0  ,3 , 5000);
g.addAresta(0  ,4 , 2236);
g.addAresta(0  ,5 , 4000);
g.addAresta(0  ,6 , 6324);
g.addAresta(0  ,7 , 3605);
g.addAresta(0  ,8 , 4242);
g.addAresta(0  ,9 , 2000);
g.addAresta(0  ,10, 5830);
g.addAresta(0  ,11, 6000);
g.addAresta(1  ,2 , 1414);
g.addAresta(1  ,3 , 3000);
g.addAresta(1  ,4 , 2236);
g.addAresta(1  ,5 , 4242);
g.addAresta(1  ,6 , 5099);
g.addAresta(1  ,7 , 2236);
g.addAresta(1  ,8 , 2000);
g.addAresta(1  ,9 , 1414);
g.addAresta(1  ,10, 4000);
g.addAresta(1  ,11, 5830);
g.addAresta(2  ,3 , 2236);
g.addAresta(2  ,4 , 1000);
g.addAresta(2  ,5 , 2828);
g.addAresta(2  ,6 , 4000);
g.addAresta(2  ,7 , 1000);
g.addAresta(2  ,8 , 1414);
g.addAresta(2  ,9 , 2000);
g.addAresta(2  ,10, 3162);
g.addAresta(2  ,11, 4472);
g.addAresta(3  ,4 , 2828);
g.addAresta(3  ,5 , 3000);
g.addAresta(3  ,6 , 2236);
g.addAresta(3  ,7 , 1414);
g.addAresta(3  ,8 , 1000);
g.addAresta(3  ,9 , 4123);
g.addAresta(3  ,10, 1000);
g.addAresta(3  ,11, 3605);
g.addAresta(4  ,5 , 2236);
g.addAresta(4  ,6 , 4123);
g.addAresta(4  ,7 , 1414);
g.addAresta(4  ,8 , 2236);
g.addAresta(4  ,9 , 2236);
g.addAresta(4  ,10, 3605);
g.addAresta(4  ,11, 4123);
g.addAresta(5  ,6 , 2828);
g.addAresta(5  ,7 , 2236);
g.addAresta(5  ,8 , 3162);
g.addAresta(5  ,9 , 4472);
g.addAresta(5  ,10, 3162);
g.addAresta(5  ,11, 2000);
g.addAresta(6  ,7 , 3000);
g.addAresta(6  ,8 , 3162);
g.addAresta(6  ,9 , 6000);
g.addAresta(6  ,10, 1414);
g.addAresta(6  ,11, 2000);
g.addAresta(7  ,8 , 1000);
g.addAresta(7  ,9 , 3000);
g.addAresta(7  ,10, 2236);
g.addAresta(7  ,11, 3605);
g.addAresta(8  ,9 , 3162);
g.addAresta(8  ,10, 2000);
g.addAresta(8  ,11, 4242);
g.addAresta(9  ,10, 5099);
g.addAresta(9  ,11, 6324);
g.addAresta(10 ,11, 3162);

console.time('tempo: ')
const res = g.caixeiro(0);
console.timeEnd('tempo: ')

const rota = res.rota;
const peso = res.peso;
console.log(rota, peso)