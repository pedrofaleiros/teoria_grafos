# Quarto Trabalho de Tópicos em Sistemas de Programação: Modelagem Computacional
# Implementação de solução para o problema do caixeiro viajante
# Discente: Valesca Moura

# Problema resolvido baseado no algoritmo guloso "Método do Vizinho Mais Próximo" 
# e realização de swaps para melhora da solução

NUM_OF_ELEMENTS = 0
ADJACENCE_MATRIX = []
WAY = []
INFINITY = 1

# Ler matriz de adjacências
def read_matrix(num_of_cities=0) -> None:
    global INFINITY, NUM_OF_ELEMENTS, ADJACENCE_MATRIX

    num_of_cities = int(input('Informe o número de cidades: '))

    print('Informe cada uma das linhas da matriz de adjacências: ')
    # Ler cada linha da matriz de adjancências
    for i in range(num_of_cities):
        distances = list(map(float, input().split())) 
        ADJACENCE_MATRIX.append(distances)

    # Calcular um valor "infinito" através da soma dos custos 
    for distance in distances:
        INFINITY += distance

    # Inicializar número de elementos
    NUM_OF_ELEMENTS = num_of_cities

# Encontrar bom caminho utilizando um algoritmo guloso (Método do Vizinho Mais Próximo)
# Verificando sempre quem é o vizinho mais "próximo" e tem o melhor custo
def find_way() -> None:
    global NUM_OF_ELEMENTS, INFINITY, WAY, ADJACENCE_MATRIX

    is_selected = [False for i in range(NUM_OF_ELEMENTS)] # vetor que marca nós selecionados
    is_selected[0] = True # Incluir nó 0 no caminho

    # Inicializar vetor de caminho
    WAY = [0 for i in range(NUM_OF_ELEMENTS + 1)]

    for i in range(NUM_OF_ELEMENTS):
        selected_neighbor = 0 # a cada iteração o nó selecionado é o 0
        best_cost = INFINITY # a cada iteração o melhor custo é infinito
        
        for j in range(NUM_OF_ELEMENTS):
            # se o nó j não está selecionado e
            # a matriz de adjancencias for diferente de 0 (pois ser 0 indica um caminho do nó para ele mesmo) e
            # o melhor custo atual for maior que o custo de seguir para o nó j
            if not is_selected[j] and ADJACENCE_MATRIX[i][j] != 0 and best_cost > ADJACENCE_MATRIX[i][j]:
                selected_neighbor = j # nó j é o novo caminho
                best_cost = ADJACENCE_MATRIX[i][j] # o novo melhor custo é o custo de seguir para nó j
                
        WAY[i+1] = selected_neighbor # Adicionar o vizinho selecionado ao caminho
        is_selected[selected_neighbor] = True # Marcar vizinho selecionado

# Calcular custo para o caminho selecionado
def calculate_cost(way) -> float:
    global NUM_OF_ELEMENTS, ADJACENCE_MATRIX

    cost = 0

    for i in range(NUM_OF_ELEMENTS):
        city_A = way[i] 
        city_B = way[i+1]
        cost += ADJACENCE_MATRIX[city_A][city_B]
    
    return cost       

# Exibir caminho na tela
def show_way() -> None:
    global WAY

    way = 'Caminho:'
    for i in range(len(WAY)):
        way += ' ' + str(WAY[i]+1) + ' '
        if i != len(WAY)-1:
            way += '->'

    print(way)

# Realização de swaps para melhorar a solução
def swap() -> None:
    global NUM_OF_ELEMENTS, WAY, ADJACENCE_MATRIX

    way_aux = WAY[:] # copiar caminho obtido na primeira solução para um vetor auxiliar
    best_cost = calculate_cost(WAY) # melhor custo atual

    for i in range(1, NUM_OF_ELEMENTS):
        for j in range(i+1, NUM_OF_ELEMENTS):
            way_aux[i], way_aux[j] = way_aux[j], way_aux[i] # swap

            cost = calculate_cost(way_aux)

            if cost < best_cost:
                best_cost = cost
                WAY = way_aux[:]


if __name__ == '__main__':
    read_matrix() # Ler matriz
    find_way()    # Encontrar solução inicial baseada no vizinho mais próximo
    
    # Realizar swaps a fim de melhorar a solução
    # Método swap é chamado múltiplas vezes para minimizar mais os custos
    for i in range(5):
        swap()

    # Exibir resultados
    show_way()
    cost = calculate_cost(WAY)
    print('Custo: ', cost)
 

'''
Input example
Cities = 6
0 13.5 11.5 7.4 7.7 4.5
15.7 0 5.2 12.1 23.1 20.0
10.1 7.2 0 7.8 14.4 12.1
7.8 11.2 7.1 0 7.2 4.9
9.3 21.0 15.7 9.0 0 6.4
4.7 16.4 12.2 5.5 4.0 0
'''   