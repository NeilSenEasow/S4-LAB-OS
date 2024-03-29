#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  

int main() {
    pid_t child_pid;
    int status;

    // Create a child process
    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d) is running...\n", getpid());
        sleep(2);  // Simulate some work
        printf("Child process (PID: %d) is done.\n", getpid());
        exit(0);
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) is waiting for the child process (PID: %d)...\n", getpid(), child_pid);
        waitpid(child_pid, &status, 0);  // Corrected wait function
        printf("Parent process (PID: %d) received status: %d\n", getpid(), status);
    } else {
        // Fork failed
        perror("Fork failed");
        exit(1);
    }

    return 0;
}
