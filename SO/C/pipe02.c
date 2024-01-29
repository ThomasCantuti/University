#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int pipe_t[2];

int main (int argc, char** argv) {

    int *pid;
    pipe_t *p0pi;
    int N = 3;

    pid = (int *) malloc(N * sizeof(int));
    p0pi = (pipe_t*) malloc(N * sizeof(pipe_t));

    for (int i = 0; i < N; i ++) {
        
        pid[i] = fork();

        if (pid[i] < 0) {
            perror("fork fallita");
            exit(0);
        }
        if (pid[i] == 0) {

            if (p0pi[i] < 0) {
                perror("pipe fallita");
                exit(1);
            }

            // p0pi[0][0] -> lettura pipe
            // p0pi[0][1] -> scrittura pipe

            // p0pi[1][0] -> lettura pipe
            // p0pi[1][1] -> scrittura pipe

        } else if (pid[i] > 0) {
            // istruzioni padre
        }
    }

    free(p0pi);

    return 0;
}