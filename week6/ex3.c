#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void pressed(){
	printf("Ctrl+C has been pressed\n");
}

int main(){
    	while(1){
		signal(SIGINT, pressed);
        	sleep(1);
    	}
	return 0;
}
