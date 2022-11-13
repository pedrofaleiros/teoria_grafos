import matplotlib.pyplot as plt
import numpy as np

pontos = [
	[0, 0],
	[10, 2],
	[8, 4],
	[6, 6],
	[10, 8],
	[2, 10],
	[3, 4]
]

x = []
y = []

for ponto in pontos:
	x.append(ponto[0])
	y.append(ponto[1])

x.append(pontos[0][0])
y.append(pontos[0][1])

plt.plot(x, y)
plt.show()