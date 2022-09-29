class Vertice:
    def __init__(self):
        self.visitado = 0
        self.distancia = 0
        self.lista_adj = []

    def addAresta(self, valor):
        self.lista_adj.append(valor)

vertices = []

n = int(input('n: '))

for i in range(n+1):
    vertices.append(Vertice())

while True:
    x, y = input("Digite dois números ").split()
    x = int(x)
    y = int(y)

    if x == -1 or y == -1:
        break

    vertices[x].addAresta(y)
    vertices[y].addAresta(x)

for i in range(1, n+1):
    print(f'\n{i} -> ', end='')
    for j in range(len(vertices[i].lista_adj)):
        print(vertices[i].lista_adj[j], end=' ')

