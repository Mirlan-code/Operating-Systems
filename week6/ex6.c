#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    	int status = 0, fd[2];
	pipe(fd);
    	printf("Pipe has been created\n");
	
	pid_t child1 = fork();
    	printf("First process has been forked\n");
	
    	pid_t child2 = fork();
    	printf("Second process forked\n");

    	if (child1 != 0 && child2 != 0){
        	write(fd[1], &child2, sizeof(child2));
        	printf("Parent writes second process pid\n");
        	printf("Parent waits for state changes in second child\n");
        	waitpid(child2, &status, 0);
        	printf("%d", status);
        	exit(0);
    	}
    	else if (child1 == 0){
        	printf("Inside the first process\n");
        	read(fd[0], &child2, sizeof(child2));
       		printf("First process reads data from pipe\n");
        	printf("First process sleeps\n");
        	sleep(2);
        	printf("First process sends signal to the second process\n");
        	kill(child2, SIGSTOP);
        	printf("Signal has been sent\n");
    	}
    	else if (child2 == 0){
        	printf("Second process works\n");
        	while (1){
            		printf("Second process alive!\n");
            		sleep(1);
        	}
    	}

	return 0;
}
