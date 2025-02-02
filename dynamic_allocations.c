#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, *ptr, sum=0;
  printf("Enter number of elements: ");
  scanf("%d",&n);
  //memory allocated using malloc
  ptr=(int*)malloc(n*sizeof(int));
  if(ptr==NULL) {
    perror("malloc:");
    exit(EXIT_FAILURE); 
  }
  printf("enter elements : ");
  for(i=0; i<n; i++) {
    scanf("%d",ptr+i);
    sum += *(ptr+i);
   }
  printf("Sum=%d",sum);
  free(ptr);
  return 0;
}
