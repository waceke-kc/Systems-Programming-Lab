#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
int sfd, dfd;   
char *src, *dest;
struct stat sb;
size_t filesize;
    /* SOURCE */     
sfd = open(argv[1], O_RDWR);
if (sfd == -1) {
perror("foo open:");
exit(EXIT_FAILURE);
}
fstat(sfd, &sb);
filesize = sb.st_size;

//printf("Size foo : %lu\n", (uint64_t)sb.st_size);

dfd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (dfd  == -1) {
perror("bar open:");
exit(EXIT_FAILURE);
}
//fstat(fd_read, &sb);
//printf("Size bar: %lu\n", (uint64_t)sb.st_size);
ftruncate(dfd, filesize);

src = mmap(NULL, filesize, PROT_READ|PROT_WRITE, MAP_SHARED, sfd, 0);
if (src == MAP_FAILED) {
perror("mmap src:");
exit(EXIT_FAILURE);
}

dest = mmap(NULL, filesize, PROT_READ|PROT_WRITE, MAP_SHARED, dfd, 0);
if (dest == MAP_FAILED) {
perror("mmap dest:");
exit(EXIT_FAILURE);
}

memcpy( dest, src, filesize);

munmap(src, filesize);
munmap(dest, filesize);

//close(dfd);
//close(sfd);
return 0;
}
