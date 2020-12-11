#include <stdio.h>
#include <unistd.h>

#include <sys/wait.h>

int main(int argc, char **argv) {
//    pid_t pid = fork();
    pid_t pid = fork();
    if (pid == -1) {
        perror("process creation");
    }
    if (!pid) {  // child
        execvp(argv[1], argv + 1);
        perror("exec");
        return 1;
    }
    int status;
    do {
        pid = waitpid(-1, &status, 0);
    } while (!WIFEXITED(status));
    printf("Process %d exited with status %d", pid, WEXITSTATUS(status));
    if (WIFSIGNALED(status)) {
        printf(" (interrupted by signal %d)", WTERMSIG(status));
    }
    puts("");
    return status;
}
