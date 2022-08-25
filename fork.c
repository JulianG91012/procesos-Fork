#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int contador;
int main()
{
    int pid, pid1, pid2;

    pid = fork();

    if (pid < 0)
    {
        printf("Fallo del fork");
    }
    else if (pid == 0)
    {
        wait(NULL);
        printf("Hijo[1] --> PID: %d, PPID: %d\n", getpid(), getppid());
    }
    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            wait(NULL);
            printf("Hijo[2] --> PID: %d, PPID: %d\n", getpid(), getppid());
        }
        else
        {
            pid2 = fork();
            if (pid2 == 0)
            {
                printf("Hijo[3] --> PID: %d, PPID: %d\n", getpid(), getppid());
            }
            else
            {
                printf("Padre --> PID: %d, PPID: %d\n", getpid(), getppid());
            }
        }
    }
    return 0;
}