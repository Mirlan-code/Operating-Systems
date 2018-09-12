#include <stdio.h>

int main(){
	int n = getpid();
	fork();
	if(n == getpid()){
		printf("Hello from parent [PID - %d]\n", getpid());
	}
	else{
		printf("Hello from child [PID - %d]\n", getpid());
	}
	return 0;
}
