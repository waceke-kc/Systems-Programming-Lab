#include  <stdio.h>

int main(){
	// initialize a stream 
	FILE *stream = stdin;
	char c;
	
	// read a character from the keyboard
	c = getchar();
	printf("Character read: %c\n", c);
	
	// Push it back onto the stream
	ungetc(c, stream);

	// read it again
	c = getchar();
	printf("Character read again: %c\n", c);
	return 0;
}
