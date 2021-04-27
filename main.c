#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	srand (time (NULL));
	int N = 100;
	int  A[N][N], B[N][N], C[N][N];
	
	//init arrays
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			A[i][j] = rand () % 100;
			B[i][j] = rand () % 100;
			C[i][j] = 0;//rand () % 1000000;
		}
		
	}
	
	//compute matrix multiplication
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			for (int k = 0; k < N - 1; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	
	printf ("%d \n", C[5][7]);
	printf ("Hello, World!\n");
	
	
	return 0;
}
