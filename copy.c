#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 1024


int main(int argc, char *argv[]){
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc != 3 || strcmp(argv[1], "--help") == 0) {
        printf("%s old-file new-file\n", argv[0]);
        return 0;
    }

    /* Open input and output files */
    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
        printf("opening file %s", argv[1]);

    openFlags = O_CREAT | O_WRONLY | O_TRUNC | O_SYNC;
#ifdef SYNC
    openFlags |= O_SYNC;
#endif
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;      /* rw-rw-rw- */
    outputFd = open(argv[2], openFlags, filePerms);
    if (outputFd == -1) {
        printf("opening file %s", argv[2]);
        return 0;
    }

    while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
        if (write(outputFd, buf, numRead) != numRead)
            printf("couldn't write whole buffer");
    if (numRead == -1)
        printf("read");

    if (close(inputFd) == -1)
        printf("close input");
    if (close(outputFd) == -1)
        printf("close output");

    return (0);
}