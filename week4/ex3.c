#include <stdio.h>
#include <stdlib.h>
#define maxn 1000
void type_prompt(){
	printf("print command:  ");
}
void read_command(char *command){
	scanf("%s", command);
}

int main(void){

	char command[maxn];

	while(1){
		type_prompt();
		read_command(command);
		system(command);
	}
	return EXIT_SUCCESS;
}

