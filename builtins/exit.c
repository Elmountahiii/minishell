/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:53:57 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/08 16:45:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int check_if_number(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	our_exit(t_command *command, t_be_executed	*to_execute, int procss)
{
	(void )to_execute;
	if (!procss)
		printf("exit\n");
	if (count_array_str(command->command_args) == 1)
		exit(exit_status);
	else if (!check_if_number(command->command_args[1]))
	{
		write(2, "minishell: exit: ", 12);
		write(2, command->command_args[1], ft_strlen(command->command_args[1]));
		write(2, ": numeric argument required\n", 28);
		exit(255);
	}
	else if (count_array_str(command->command_args) > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		exit_status = 1;
	}else
	{
		exit(ft_atoi(command->command_args[1]));
	}
}
