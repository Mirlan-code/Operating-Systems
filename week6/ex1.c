#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#define maxn 1000
void main()
{
    int n = maxn, fd[2];
    char s[] = "text", empty[n];
    if (pipe(fd) == 0)
    {
        write(fd[1], s, strlen(s));
        read(fd[0], empty, n);
        printf("%s\n", empty);
    }
}
