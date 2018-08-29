#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
	int n;
	sscanf(argv[1], "%d", &n);
	for(int i = 1; i<=n; i++){
		char s[2 * n - 1];
		for(int j = 0; j < 2 * n - 1; j++){
			s[j] = ' ';
		}
		for(int j =  n - i; j < n + i - 1; j++){
			s[j] = '*';
		}
		for(int j = 0; j < 2 * n - 1; j++){
			printf("%c", s[j]);
		}
		printf("\n");
	}
	return 0;
}
