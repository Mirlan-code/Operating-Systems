#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define sz 5
#define ll long long

int main() {
	char buff[sz];

	if (setvbuf(stdout, buff, _IOLBF, sizeof(buff))) {
		perror("failed to change buff");
		return EXIT_FAILURE;
	}
	printf("H"); sleep(1);
	printf("e"); sleep(1);
	printf("l"); sleep(1);
	printf("l"); sleep(1);
	printf("o"); sleep(1);

	putchar('\n');
	return 0;
}