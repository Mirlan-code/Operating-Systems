#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#define maxn 1000
int main(){
	int n = maxn, fd[2];
	char s[] = "text", empty[n];
	pid_t child;
	if (pipe(fd) == 0){
		child = fork();
		if(child != 0){
			write(fd[1], s, strlen(s));
		}
        	else{
			read(fd[0], empty, n);
        		printf("from child %s\n", empty);
		}
    	}

	return 0;
}




