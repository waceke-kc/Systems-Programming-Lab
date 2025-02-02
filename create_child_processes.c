#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid, i;

    // Create a new process
    pid = fork();

    if (pid > 0) {
        // This is the parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        for (i = 0; i < 10; i++)
            printf("\t\t\tPARENT %d\n", i);
    } else if (pid == 0) {
        // This is the child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        for (i = 0; i < 10; i++)
            printf("CHILD %d\n", i);
    }

    return 0;
}
