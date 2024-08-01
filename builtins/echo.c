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

void	our_echo(char **str)
{
	int new_line = 1;
	int i = 1;
	while (str[i])
	{
		if (i == 1 && is_nn(str[i]))
		{
			new_line = 0;
		}else
		{
			write(1, str[i], ft_strlen(str[i]));
			if (str[i + 1])
				write(1, " ", 1);
		}
		i++;
	}
	if (new_line)
		write(1, "\n", 1);
	// handle -n oprion
	// write(1, str, ft_strlen(str));
	// write(1, "\n", 1);
}