#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void pressed_sig_usr_1(){
    printf("SIGUSR1 has pressed\n");
}

void pressed_sig_stop(){
    printf("SIGSTOP has pressed\n");
}

void pressed_sig_kill(){
    printf("SIGKILL has pressed\n");
}

void pressed_ctrl_c(){
    printf("SIGINT has pressed\n");
}

int main(){
	while(1){
        	signal(SIGINT, pressed_ctrl_c);
		signal(SIGKILL, pressed_sig_kill);
		signal(SIGSTOP, pressed_sig_stop);
		signal(SIGUSR1, pressed_sig_usr_1);
		sleep(1);
    	}
	return 0;
}
