
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main()
{
        FILE *read_stream, *write_stream;
	char buff[1024];
	size_t nr, nw;
	size_t  element_size = 16;
	size_t no_of_elements = sizeof(buff)/element_size;
	read_stream = fopen("foo.txt", "r");
	if (!read_stream){
	  perror("Error opening the first file");
	  return 1;	
	}	
	nr = fread(buff, element_size, no_of_elements, read_stream);
	if (nr == 0){
	    perror("Error reading the first file");
	    return 1;
	}
        fclose(read_stream);

	write_stream = fopen("bar.txt", "w");
	if(!write_stream){
	       perror("Error opening the second file");
	       return 1;
	}
	nw = fwrite(buff, element_size, nr, write_stream);
	if (nw < nr){
	        perror("Error writing the contents to a file");
	        return 1;
	}
	fclose(write_stream);
        
        return 0;
}


