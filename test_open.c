#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main()
{
	int fd1, fd2;
	fd1 = open("foo.txt", O_RDONLY, 0);
	if (fd1 == -1){
	 perror("The error is");
	 return 1;
	}
    close(fd1);
	fd2 = open("baz.txt", O_RDONLY, 0);
	if (fd2 == -1){
	 perror("The error is");
	 return 1;
	}else {
	 printf("fd2 = %d\n", fd2);
	}
	close(fd2);
	return 1;
}
