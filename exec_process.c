#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
char *temp1,*temp2;
temp1="Funny";
temp2="world";
//execlp("echo", "echo", temp1, temp2, NULL);
execlp("ls", "/", NULL);
printf("Error");
}
