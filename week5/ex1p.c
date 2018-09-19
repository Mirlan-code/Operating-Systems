#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define maxn 1000
#define ll long long
void * PrintHello(int i){
	printf("Hello from thread %d - I was created in iteration %d !\n", (int)pthread_self(), i);
	pthread_exit(NULL);
}
int main(int argc, char * argv[]){
	int thread_id[maxn];
	int n = atoi(argv[1]);
	for(int i = 0; i<n; i++){
		int rc = pthread_create(&thread_id[i], NULL, PrintHello, i);
		if(rc){
			printf("\n ERROR: return code from pthread_create is %d", rc);
			exit(1);
		}
		printf("\n I am thread %d. Created new thread(%d) in iteration %d...\n", (int)pthread_self(), (int) thread_id[i], i);
		//if(i%5==0) sleep(1);
	}
	pthread_exit(NULL);
}
