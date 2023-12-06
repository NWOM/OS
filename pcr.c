//vim parent_child_relationship.c
//gcc parent_child_relationship.c -o parent_child
//./parent_child

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Error occurred
        fprintf(stderr, "Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process created with PID: %d\n", getpid());
    } else {
        // Parent process
        printf("Parent process with PID: %d created a child with PID: %d\n", getpid(), pid);
    }

    return 0;
}



