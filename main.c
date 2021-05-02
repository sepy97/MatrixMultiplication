#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 100

int A[N][N], B[N][N], C[N][N];

struct thread_args {
	int threadId;      //id of a current thread
	int numOfThreads;  //total number of threads
};

void loop (void* args)
{
	int inc = ((struct thread_args *) args )->numOfThreads;
	int id = ((struct thread_args *) args )->threadId;
	
	//printf ("inc is %d; id is %d\n", inc, id);
	
	for (int i = id; i < N - 1; i += inc)
	{
		for (int j = 0; j < N - 1; j++)
		{
			for (int k = 0; k < N - 1; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
}

int main ()
{
	srand (time (NULL));
	
	int threadNum = 4;
	pthread_t my_thread [threadNum+1];
	
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
	for (int id = 1; id <= threadNum; id++)
	{
		struct thread_args *thr = (struct thread_args *)malloc(sizeof(struct thread_args));
		thr->numOfThreads = threadNum;
		thr->threadId = id;
		pthread_create (&my_thread [id], NULL, &loop, (void*) thr);
		//loop ();
	}
	
	for (int id = 1; id <= threadNum; id++)
	{
		pthread_join (my_thread [id], NULL);
	}
	
	printf ("%d \n", C[5][7]);
	printf ("Hello, World!\n");
	
	return 0;
}
