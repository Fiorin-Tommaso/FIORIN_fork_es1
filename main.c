#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i < n + 1 ; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            printf("fork failed\n");
        }
        if (pid == 0) {
            printf("child: %d, numero %d \n",i, getpid());
        } else {
            //printf("parent %d, numero: %d \n",i, getppid());
            wait(0);
            break;
        }
    }
    return 0;
}