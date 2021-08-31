#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    
    if (pid < 0)
    {
        printf("Failed to fork\n");
        return -1;
    }
    
    //Parent Proc.
    
    else if (pid > 0)
    {
        printf("Parent PID: %d\n", getpid());
        sleep(30);
    }
    
    else
    {
        printf("Child PID: %d\n", getpid());
        exit(0);
    }
    
    return 0;
    
}