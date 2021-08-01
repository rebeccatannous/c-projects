#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void conjecture(int n);
int main()
{
    int n;
    pid_t pid;

    printf("Collatz Conjecture \n");
    printf("Enter a number strictly greater than 0\n");
    scanf("%d", &n);

    while (n <= 0)
    {
        printf("Number should be strictly greater than 0, please enter again\n");
        scanf("%d", &n);
    }
    pid = fork();
    if (pid == 0)

        conjecture(n);
        else
        wait(NULL);

    return 0;
}

void conjecture(int n)
{
    if (n == 1)
    {
        return;
    }
    else if (n % 2 == 0)
    {
        printf("%d ", n / 2);
        conjecture(n / 2);
    }
    else
    {
        printf("%d ", 3 * n + 1);
        conjecture(3 * n + 1);
    }
}

