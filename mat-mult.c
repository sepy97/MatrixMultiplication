#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

#define N 1024

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
	
	//for (int i = id; i < N - 1; i += inc)
	//{
	for (int j = 0; j < inc; j++)//N - 1; j++)
	{
		for (int k = 0; k < inc; k++)// N - 1; k++)
		{
			C[id-1/*i*/][j] = C[id-1/*i*/][j] + A[id-1/*i*/][k] * B[k][j];
			//printf ("%d \n", C[id-1][j]);
		}
	}
	//}
}

int main (int argc, char** argv)
{
	srand (time (NULL));
	
	int threadNum = 4;
	if (argc > 1) threadNum = atoi (argv[1]);
	pthread_t my_thread [threadNum+1];
	
	struct timeval start, end;
	
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
	
	gettimeofday(&start, NULL);
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
	gettimeofday(&end, NULL);
	
	/*(printf ("%d \n", C[5][7]);
	printf ("Hello, World!\n");*/
	printf ("%d ; %.4f ; \n ", C[1][1],
	        (double)((end.tv_sec * 1000000 + end.tv_usec) -
	                 (start.tv_sec * 1000000 + start.tv_usec))/1000000.0);
	
	return 0;
}