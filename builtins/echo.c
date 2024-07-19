#include "../minishell.h"

// int ft_strlen(char *s)
// {
// 	int i = 0;
// 	if (s == NULL)
// 	{
// 		write(1, "s is null\n", 9);
// 		return 0;
// 	}
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

void	our_echo(char *str)
{
	// handle -n oprion
	write(1, str, ft_strlen(str));
}