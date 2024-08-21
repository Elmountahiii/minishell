/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:17 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 11:23:56 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_executed(t_command *command)
{
	if ((command->in_type == FILE_IO && command->in_file == NULL)
		|| (command->out_type == FILE_IO && command->out_file == NULL))
		return (0);
	
	if (command->is_ambiguous)
	{
		// write(2, "minishell: ", 11);
		// write(2, command->ambiguous_name, ft_strlen(command->ambiguous_name));
		// write(2, ": ambiguous redirect\n", 22);
		return (0);
	}
	if (command->fd_in == -1 || command->fd_out == -1)
		return (0);
	return (1);
}
