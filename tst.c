#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i;
    int pid;

	i = 0;
	pid = 1;
	while (i < 5)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("I am the childd\n");
			break ;
		}
		printf("I am the parentt\n");
		i++;
	}
}
