#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int contador = 0;

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
        for (int i = 0; i <= 5; i++)
        {
            contador = i + contador;
            printf("Hijo[1] --> PID: %d, PPID: %d ID: %d\n", getpid(), getppid(), contador);
        }
        printf("\n");
    }
    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            wait(NULL);
            for (int i = 0; i <= 5; i++)
            {
                contador = i + contador;
                printf("Hijo[2] --> PID: %d, PPID: %d ID: %d\n", getpid(), getppid(), contador);
            }
            printf("\n");
        }
        else
        {
            pid2 = fork();
            if (pid2 == 0)
            {
                for (int i = 0; i <= 5; i++)
                {
                    contador = i + contador;
                    printf("Hijo[3] --> PID: %d, PPID: %d ID: %d\n", getpid(), getppid(), contador);
                }
                printf("\n");
            }
            else
            {
                wait(NULL);
                wait(NULL);
                wait(NULL);
                for (int i = 0; i <= 5; i++)
                {
                    contador = i + contador;
                    printf("Padre --> PID: %d, PPID: %d ID: %d\n", getpid(), getppid(), contador);
                }
                printf("\n");
            }
        }
    }
    return 0;
}