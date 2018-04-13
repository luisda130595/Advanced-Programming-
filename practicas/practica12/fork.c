#include <stdio.h>
#include <unistd.h>

int main() 
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        execl("/cygdrive/c/Windows/System32/calc.exe", "calc.exe", (char *)0);
        printf("Hola mundo soy el hijo \n");
    }
    else
    {
        printf("Hola mundo soy el padre \n");
    }

    return 0;
}