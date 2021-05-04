#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

#define N 256

int A[N][N], B[N][N], C[N][N];

int main (int argc, char** argv)
{
	srand (time (NULL));
	
	//by def, size of arrays is NxN
	int arrSize = N;
	//receive size of arrays as a command line argument
	if (argc > 1) arrSize = atoi (argv[1]);
	
	//structs for time measurements
	struct timeval start, end;
	
	//init arrays
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			A[i][j] = rand () % 100;
			B[i][j] = rand () % 100;
			C[i][j] = 0;
		}
		
	}
	
	//time measurements
	gettimeofday(&start, NULL);
	//compute matrix multiplication
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - 1; j++)
		{
			for (int k = 0; k < arrSize - 1; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	//time measurements
	gettimeofday(&end, NULL);
	
	printf ("%d ; %.4f ; ", C[5][7],
	       (double)((end.tv_sec * 1000000 + end.tv_usec) -
	                (start.tv_sec * 1000000 + start.tv_usec))/1000000.0);
	
	return 0;
}
