//Base del código en: https://www.geeksforgeeks.org/using-fork-produce-1-parent-3-child-processes/?ref=lbp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Variable global para crear copias en cada uno de los hijos
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
        //Se usan los wait para que no compitan por los recursos de la máquina
        wait(NULL);
        // Acumulador de los hijos
        for (int i = 0; i <= 5; i++)
        {
            contador = i + contador;
            // Se muestra el PID del hijo actual
            printf("Hijo[1] --> PID: %d, PPID: %d ID: %d\n", getpid(), getppid(), contador);
        }
        printf("\n");
    }
    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            //Se usan los wait para que no compitan por los recursos de la máquina
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
                //Se usan los wait para que no compitan por los recursos de la máquin
                wait(NULL);
                for (int i = 0; i <= 5; i++)
                {
                    contador = i + contador;
                    printf("Hijo[3] --> PID: %d, PPID: %d ID: %d\n", getpid(), getppid(), contador);
                }
                printf("\n");
            }
            else
            {
                //Se agregan 3 waits, para que el padre espere a que los 3 hijos terminen para realizar sus operaciones
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