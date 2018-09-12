#include <stdio.h>
#include <stdlib.h>
#define maxn 1000
void type_prompt(){
	printf("print command:  ");
}
void read_command(char *command){
	//reads the whole line from the console (e.g. touch ex5.c)
	gets(command);
}

int main(void){

	char command[maxn];

	while(1){
		type_prompt();
		
		read_command(command);
		//gives the command (might be line with parametres) to the UNIX shell
		system(command);
	}
	return EXIT_SUCCESS;
}
