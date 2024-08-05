/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:53:57 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/05 16:11:56 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	our_exit(t_command *command, t_be_executed	*to_execute, int procss)
{
	(void )to_execute;
	if (!procss)
		printf("exit\n");
	if (command->command_args[1])
	{
		exit(ft_atoi(command->command_args[1]));
	}else
	{
		exit(exit_status);
	}
}