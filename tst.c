#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int exit_status = 0;

int make_one(void)
{
	int i = 0;
	sleep(1);
	printf("I am one\n");
	return 1;
}

void make_two(void)
{
	printf("I am two\n");
	exit(120);
}

int main(void)
{
	int status;
	int pid;
	int i = 0;

	pid = fork();
	if (pid == 0)
	{
		make_one();
		// exit(154);
	}
	// while (i < 2)
	// {
	kill(pid, SIGINT);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		printf("yes normally %d\n", WEXITSTATUS(status));
	}else if (WIFSIGNALED(status))
	{
		printf("yes signaled\n %d\n", WTERMSIG(status));
	}
	// printf("stoped normally status = %d\n", WEXITSTATUS(status));
	// 	i++;
	// }
	// i = 0;
	// while (i < 2)
	// {
	// 	printf("stoped status[%d] = %d\n", i, WEXITSTATUS(status[i]));
	// 	i++;
	// }
}
