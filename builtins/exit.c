/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:53:57 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/23 12:38:09 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_if_number(char *str)
{
	int	i;

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

int	check_overflow(const char *str)
{
	long long	check;
	long long	n;
	int			sign;

	n = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		check = n;
		n = n * 10 + sign * (*str - 48);
		if (check > n && sign == 1)
			return (1);
		else if (check < n && sign == -1)
			return (1);
		str++;
	}
	return (0);
}

void	our_exit(t_command *command, t_be_executed	*to_execute, int procss)
{
	(void )to_execute;
	if (count_array_str(command->command_args) == 1)
		exit(g_exit_status);
	else if (!check_if_number(command->command_args[1])
		|| check_overflow(command->command_args[1]))
	{
		write(2, "minishell: exit: ", 17);
		write(2, command->command_args[1], ft_strlen(command->command_args[1]));
		write(2, ": numeric argument required\n", 28);
		exit(255);
	}
	else if (count_array_str(command->command_args) > 2)
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		if (procss)
			exit(1);
		g_exit_status = 1;
	}
	else
		exit(ft_atoi(command->command_args[1]));
}
