#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define maxn 1000

int main(){
	while (1){
		int n = getpid();
		char *command = NULL;
		size_t  bufsize = 0;
		//reads the first string (main command)
		ssize_t read = getline(&command, &bufsize, stdin);

		char *argv[10]; //array of params

		int x = 0;
		int start = 0;
		for(int i = 0; i < read - 1; i++){
			if(command[i] == ' '){
				argv[x] = (char *)malloc(i-start);
				strncpy(argv[x], command+start, i-start);
				x++;
				start = i+1;
			}
		}

		argv[x] = malloc(read-start-1);
		strncpy(argv[x], command+start, read-start-1);
		x++;
		//starts the program in background
		fork();
		if (n != getpid()){
			char * arg[x+1];
			for(int i=0;i<x;i++){
				arg[i]=argv[i];
			}
			arg[x] = NULL;
			execvp(argv[0], arg);
			break;
		}
	}
	return 0;
}
