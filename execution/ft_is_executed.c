/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:17 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/20 12:11:08 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_executed(t_command *command)
{
	if (command->is_ambiguous)
	{
		write(2, "minishell: ", 11);
		write(2, command->ambiguous_name, ft_strlen(command->ambiguous_name));
		write(2, ": ambiguous redirect\n", 22);
		return (0);
	}
	if (command->fd_in == -1)
	{
		return (0);
	}
	if (command->fd_out == -1)
	{
		return (0);
	}
	return (1);
}
