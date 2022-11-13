const Vertice = require("./vertice.js");

class Grafo {

	constructor(num_vertices){
		this.vertices = [];
		this.num_vertices = num_vertices;

		for(let i = 0; i < num_vertices; i++){
			this.vertices.push(new Vertice());
		}
	}

	addAresta(x, y, peso){
		this.vertices[x].addAresta(y, peso);

		this.vertices[y].addAresta(x, peso);
	}

	mostraGrafo() {
        for (let i = 0; i < this.num_vertices; i++) {
            console.log(`${i} -> ${this.vertices[i].getListaAdj()}`);
        }
    }

	getDistance(x, y){
		let lista = this.vertices[x].getCompleteList();
		let dist = 0;

		lista.forEach((e)=>{
			if(e.valor == y){
				dist = e.peso;
			}
		});
		return dist;
	}

	calcula_distancia(route){
		let distancia = 0;
		let tam = route.length;

		for(let i = 0, j = 1; i < tam-1 && j < tam; i++, j++){
			distancia += this.getDistance(route[i], route[j]);
		}
		return distancia;
	}

	tsp(origin){
		var indice = 0;
		var route = [];
		var visitados = [];
		for(let i = 0; i < this.num_vertices; i++){
			visitados.push(0);
			route.push(0);
		}

		route.push(origin)

		route[indice] = origin;
		visitados[origin] = 1;

		for(let i = 0; i < this.vertices[origin].getTamanhoLista(); i++){
			let elemento = this.vertices[origin].getListaAdj()[i]
			this.calcula(elemento, visitados, route, indice+1);
		}
	}

	calcula(elemento, visitados, route, indice){

		route[indice] = elemento;
		visitados[elemento] = 1;
		
		if(indice == this.num_vertices-1){
			console.log('route:', route, 'distancia: ', this.calcula_distancia(route));
		}else{

			for(let i = 0; i < this.vertices[elemento].getTamanhoLista(); i++){
				let el = this.vertices[elemento].getListaAdj()[i];
				if(visitados[el] == 0){
					this.calcula(el, visitados, route, indice+1);
				}
			}
		}

		visitados[elemento] = 0
	}
}

module.exports = Grafo;
