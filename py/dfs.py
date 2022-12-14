class Vertice:
    def __init__(self):
        self.visitado = 0
        self.distancia = 0
        self.lista_adj = []

class Grafo:
    def __init__(self, qtd):
        self.qtd = qtd
        self.vertices = []
        for i in range(0, qtd):
            self.vertices.append(Vertice())

    def addAresta(self, v1, v2):
        if v1 >= self.qtd or v2 >= self.qtd or v1==v2:
            return False
        self.vertices[v1].lista_adj.append(v2)

    def addVertice(self):
        self.vertices.append(Vertice())
        self.qtd += 1

    def mostra(self):
        for i in range(len(self.vertices)):
            print(i, '->', self.vertices[i].lista_adj)
    
    def mostra_distancia(self, i):
        for j in range(len(self.vertices)):
            print('distancia de', i, 'para', j, ':', self.vertices[j].distancia)

    def dfs_distancia(self, i, distancia):
        self.vertices[i].visitado = 1
        self.vertices[i].distancia = distancia
        print(i)

        for j in range(0, len(self.vertices[i].lista_adj)):
            elemento = self.vertices[i].lista_adj[j]
            if self.vertices[ elemento ].visitado == 0:
                self.dfs_distancia(elemento, distancia+1)


def main():
    n = int(input('N: '))

    graph = Grafo(n)

    while True: 
        x, y = input("Digite dois números ").split()
        x = int(x)
        y = int(y)

        if x == -1 or y == -1:
            break

        graph.addAresta(x, y)
        graph.addAresta(y, x)

    graph.mostra()


main()