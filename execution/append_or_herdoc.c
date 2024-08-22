/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_or_herdoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:06:30 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/22 16:35:26 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	assign_fd_heredc(int *fd, t_command *command)
{
	if (command->is_heredoc)
	{
		*fd = open(command->in_file, O_RDONLY | O_APPEND, 0644);
		if (*fd == -1)
			prror_exit("minishell: ", command->in_file);
	}
	else
	{
		*fd = open(command->in_file, O_RDONLY, 0644);
		if (*fd == -1)
			prror_exit("minishell: ", command->in_file);
	}
}

void	assign_fd_append(int *fd, t_command *command)
{
	if (command->is_append)
	{
		*fd = open(command->out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*fd == -1)
			prror_exit("minishell: ", command->in_file);
	}
	else
	{
		*fd = open(command->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*fd == -1)
			prror_exit("minishell: ", command->in_file);
	}
}
