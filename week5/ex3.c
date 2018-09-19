#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define maxn 1000

int used = 0;
int count = 0;

void * go(int i){
	while(1){
		if(!used){
			used = 1;
			for(int j = 0; j<i; j++) count++;
			printf("\nthread id is %d, count is equal to %d\n", (int) pthread_self(), count);
			used = 0;
			break;
		}
		else{
			sleep(1);
		}
	}
	pthread_exit(NULL);
}

int main(int argc, char * argv[]){
	pthread_t thread_id[maxn];
	int n = atoi(argv[1]);
	for(int i = 0; i<n; i++){
		sleep(1);
		printf("%d\n", i);
		int rc = pthread_create(&thread_id[i], NULL, go, i);
		if(rc){
			printf("\n ERROR\n");
			exit(1);
		}
	}
	return 0;
}
