#include <stdio.h>
#include <stdlib.h>

int main()
{

	int mat[50][50];

	int N;

	printf("\nNumero N: ");
	scanf("%d", &N);

	int maior = N;
	for (int i = 0; i < N; i++)
	{
		int x, y;

		printf("\nPar %d: ", i + 1);
		scanf("%d %d", &x, &y);

		if (x > maior || y > maior)
		{
			maior = (x > y) ? x : y;
		}

		mat[x - 1][y - 1] = 1;
		mat[y - 1][x - 1] = 1;
	}

	printf("\nMatriz de adjacencia\n");
	for (int i = 0; i < maior; i++)
	{
		for (int j = 0; j < maior; j++)
		{
			if (i == j)
			{
				mat[i][j] = 1;
			}

			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	printf("\nLista de adjacencia\n");

	for(int i = 0; i < maior; i++){
		printf("\n%d -> ",i+1);

		for(int j = 0; j < maior; j++){
			if(mat[i][j] == 1 && i != j){
				printf("%d ", j+1);
			}
		}
	}

	return 0;
}