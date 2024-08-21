/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:45:41 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 15:39:14 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_nn(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i] == 'n')
		{
			i++;
			if (str[i] == '\0')
				return (1);
		}
	}
	return (0);
}

void	asssign_values(int *new_line, int *exit_sts, int *i)
{
	*new_line = 1;
	*exit_sts = 0;
	*i = 1;
}

void	our_echo(t_command *command, int procss)
{
	int		new_line;
	int		exit_sts;
	int		i;
	char	**str;

	asssign_values(&new_line, &exit_sts, &i);
	str = command->command_args;
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
	if (new_line)
		printf("\n");
	if (procss)
		exit(exit_sts);
	else
		g_exit_status = 0;
}
