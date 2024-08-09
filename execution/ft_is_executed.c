/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:17 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 19:56:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_executed(t_command *command)
{
	if (command->fd_in == -1)
	{
		write(2, "minishell: ", 11);
		write(2, command->in_file, ft_strlen(command->in_file));
		write(2, ": No such file or directory\n", 28);
		return (0);
	}
	if (command->fd_out == -1)
	{
		write(2, "minishell: ", 11);
		write(2, command->out_file, ft_strlen(command->out_file));
		write(2, ": No such file or directory\n", 28);
		return (0);
	}
	return (1);
}
