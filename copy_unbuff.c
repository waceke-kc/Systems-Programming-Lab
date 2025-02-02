#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main()
{
        int fd_read, fd_write;
        ssize_t data_read, data_write;
        char read_buffer[1024];
        fd_read = open("foo.txt", O_RDONLY, 0);
        if (fd_read == -1){
          perror("Error opening first file");
          return 1;
        }else {
        data_read = read(fd_read, read_buffer,1024);
        if (data_read == -1){
            perror("Error reading the file");
            return 1;
          }
        }
        close(fd_read);
        fd_write = open("bar.txt", O_WRONLY, 0);
        if (fd_write == -1){
          perror("Error opening the second file");
          return 1;
        }else {
        data_write = write(fd_write, read_buffer, 1024);
        if (data_write == -1){
           perror("Error writing to the file");
            return 1;
        }
        }
        close(fd_write);
        return 1;
}
