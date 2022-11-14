import matplotlib.pyplot as plt
import numpy as np
import random

x = []
y = []

for ponto in range(10):
	p1 = random.randint(0, 15)
	p2 = random.randint(0, 15)
	x.append(p1)
	y.append(p2)

	print(p1, p2)
	plt.scatter(p1, p2, label=1)

plt.xlabel("X")
plt.ylabel("Y")
plt.title("Scatter Plot")
plt.show()