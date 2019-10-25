#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct stat buff;
    if (argc != 2)
    {
        fprintf(stderr, "nb d'arguments incorrect !\n");
        exit(1);
    }
    int k = lstat(argv[1], &buff);
    switch (buff.st_mode & S_IFMT)
    {
    case S_IFREG:
        printf(" ");
        break;
    case S_IFDIR:
        printf("d");
        break;
    case S_IFLNK:
        printf("l");
        break;
    }
    if (buff.st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    if (buff.st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");
    if (buff.st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");
    if (buff.st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");
    if (buff.st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if (buff.st_mode & S_IXGRP)
        printf("x");
    else
        printf("-");
    if (buff.st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if (buff.st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if (buff.st_mode & S_IXOTH)
        printf("x\n");
    else
        printf("-\n");
}