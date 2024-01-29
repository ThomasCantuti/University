/*

Funzioni della libreria stdlib.h
    atexit()
    exit()
    on_exit()
    system()

Funzioni della libreria stdio.h
    popen(), pclose()

Funzioni della libreria unistd.h
    _exit()
    alarm()
    execl(), execv(), execle(), execlp(), execvp()
    execve()
    fork()
    pause()
    pipe()
    sleep()

Funzioni della libreria sys/wait.h
    wait(), waitpid()

Funzioni della libreria fcntl.h:
    O_RDONLY
    O_WRONLY
    O_RDWR
    O_CREAT
    O_EXCL
    O_TRUNC
    O_APPEND
    O_NONBLOCK

Funzioni della libreria errno.h:
    ENOENT

Funzioni della libreria signal.h:
    sig_atomic_t
    kill()
    killpg()
    signal()
    SIGUSR1 -> kill -USR1 pid
    SIGUSR2 -> kill -USR2 pid
    SIGINT -> CTRL-C
    SIG_IGN -> ignora il segnale
    SIG_DFL -> applica gestione di default (del SO) del segnale

*/