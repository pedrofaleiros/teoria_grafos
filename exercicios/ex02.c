#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, e;

	scanf("%d %d", &n, &e);

	int mat[n][n];

	for (int i = 0; i < e; i++){
		int x, y;

		scanf("%d %d", &x, &y);

		mat[x - 1][y - 1] = 1;
		mat[y - 1][x - 1] = 1;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j){
				mat[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < n; i++){
		printf("\n%d -> ",i+1);

		for(int j = 0; j < n; j++){
			if(mat[i][j] == 1 && i != j){
				printf("%d ", j+1);
			}
		}
	}

	int visitados[n];

	for(int i = 0; i < n; i++) visitados[i] = 0;

	for(int i = 0; i < n; i++){
		if(visitados[i] == 0){
			
		}
	}


	printf("\n");
	return 0;
}