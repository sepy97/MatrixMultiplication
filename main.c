#include <stdio.h>

int main ()
{
	int N = 100;
	int  A[N][N], B[N][N], C[N][N];
	
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; i < N - 1; i++)
		{
			for (int k = 0; i < N - 1; i++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
				
				
			}
		}
	}
	
	printf ("%d \n", A[5][7]);
	printf ("Hello, World!\n");
	
	
	return 0;
}
