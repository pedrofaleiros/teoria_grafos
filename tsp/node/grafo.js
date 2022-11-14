const Vertice = require("./vertice.js");

class Grafo {

	constructor(num_vertices){
		this.vertices = [];
		this.num_vertices = num_vertices;
		this.rota_otima = [];
		this.menor_distancia = 9999;

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

	getDistancia(x, y){
		let tam = this.vertices[x].getTamanhoLista();
		for(let i = 0; i < tam; i++){
			let elemento = this.vertices[x].getListaAdj()[i];

			if(elemento == y){
				return this.vertices[x].getListaPeso()[i];
			}
		}

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

		return {
			'rota':this.rota_otima,
			'distancia':this.menor_distancia
		}
	}

	calcula(elemento, visitados, route, indice){

		route[indice] = elemento;
		visitados[elemento] = 1;
		
		if(indice == this.num_vertices-1){
			let dist = this.calcula_distancia(route);
			if(dist < this.menor_distancia){
				this.menor_distancia = dist;
				for(let i = 0; i <= this.num_vertices; i++){
					this.rota_otima[i] = route[i]
				}
			}
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

	caixeiro(origin){
		this.rota_otima = [...Array(this.num_vertices+1).fill(0)];
		this.menor_distancia = 999999;

		var indice = 0;
		const route = [...Array(this.num_vertices+1).fill(0)];
		const visitados = [...Array(this.num_vertices).fill(0)];
		
		visitados[origin] = 1;
		route[0] = origin;
		route[this.num_vertices] = origin;

		var tam = this.vertices[origin].getTamanhoLista();

		for(let i = 0; i < tam; i++){
			let elemento = this.vertices[origin].getListaAdj()[i]
			let distancia = this.vertices[origin].getListaPeso()[i]

			this.viajante(origin, visitados, route, indice+1, elemento, distancia);
		}

		return {
			'rota':this.rota_otima,
			'peso':this.menor_distancia
		}
	}

	viajante(origin, visitados, route, indice, elemento, distancia){

		if(distancia > this.menor_distancia) return;

		visitados[elemento] = 1;
		route[indice] = elemento;

		let tam = this.vertices[elemento].getTamanhoLista();

		for(let i = 0; i < tam; i++){
			let el_lista = this.vertices[elemento].getListaAdj()[i];
			let el_dist = this.vertices[elemento].getListaPeso()[i];

			if(visitados[el_lista] == 0){
				this.viajante(origin, visitados, route, indice+1, el_lista, distancia+el_dist);
			}
		}

		if(indice == this.num_vertices-1){
			let dist = distancia + this.getDistancia(origin, elemento);

			if(dist <= this.menor_distancia){
				this.menor_distancia = dist;
				for(let i = 0; i <= this.num_vertices; i++){
					this.rota_otima[i] = route[i]
				}
			}
		}

		visitados[elemento] = 0;
	}
}

module.exports = Grafo;
