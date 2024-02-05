#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

static volatile sig_atomic_t count = 0;

void handler () {
    printf("Numero richieste servite: %d\n", count);
    exit(0);
}

int main (int argc, char** argv) {

    int pid, fd, status, p1p2[2], p2p3[2], p3p0[2], nread;
    char filepath[200];

    // controllo argomenti

    // controllo se nomeTeatro esiste


    printf("Numero richieste servite: %d\n", count);
}