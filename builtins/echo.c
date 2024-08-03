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

void	our_echo(char **str, int procss)
{
	int new_line = 1;
	int exit_sts = 0;
	int i = 1;

	while (str[i])
	{
		if (i == 1 && is_nn(str[i]))
		{
			new_line = 0;
		}else
		{
			if (str[i][0] == '?')
			{
				printf("%i", exit_status);
			}
			else
			{
				printf("%s", str[i]);
				if (str[i + 1])
					printf(" ");
			}
		}
		i++;
	}
	if (new_line)
		printf("\n");
	if (procss)
		exit(exit_sts);
}
