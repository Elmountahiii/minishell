#include "../minishell.h"

int	is_nn(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i] == 'n')
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

void	our_echo(t_command *command, t_be_executed	*to_execute, int procss)
{
	(void )to_execute;
	int new_line = 1;
	int exit_sts = 0;
	int i = 1;
	char **str = command->command_args;

	// dup2(command->fd_out, 1);
	while (str[i] && is_nn(str[i]))
	{
		new_line = 0;
		i++;
	}
	while (str[i])
	{
		printf("%s", str[i]);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	// dup2(5, 1);
	if (new_line)
		printf("\n");
	if (procss)
		exit(exit_sts);
}
