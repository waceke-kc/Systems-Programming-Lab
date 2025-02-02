#include <stdio.h>
#include <stdlib.h>

#define NSIZE 2000000
// static array of 2000000 bytes

char x[NSIZE];
// static array of 25 bytes initialized with 'a' symbol
char z[25] = {'a'};

int main () {
  int i=0;
  for (i=0; i<NSIZE; i++) {
    x[i] = 'x';
  }
  printf("done\n");
  return 0;
}
