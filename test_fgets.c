#include <stdio.h>

int main(){
	char mystring[50];
	FILE *stream;

	printf("Enter a string: ");
	if (fgets(mystring, 50, stdin) != NULL){
		// printf("You entered: %s", mystring);
		stream = fopen("mylog.txt", "a");
		fputs(mystring, stream);
	        fclose(stream);
	}
	return 0;
}
