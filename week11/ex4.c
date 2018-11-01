#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define ll long long

int main() {
	size_t sz;
	int sfd, dfd;
	char *file1, *file2;
	sfd = open("ex1.txt", O_RDONLY);
	sz = lseek(sfd, 0, SEEK_END);
	file1 = mmap(NULL, sz, PROT_READ, MAP_PRIVATE, sfd, 0);
	dfd = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
	ftruncate(dfd, sz);
	file2 = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);
	memcpy(file2, file1, sz);
	munmap(file1, sz);
	munmap(file2, sz);
	close(sfd); close(dfd);
	return 0;
}