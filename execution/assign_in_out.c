/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:36:57 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/03 15:18:24 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_file_fd(t_command	*command, char i_o)
{
	int fd;

	fd = 1;
	if (i_o == 'i')
	{
		if (command->is_heredoc)
		{
			fd = open(command->in_file, O_RDONLY | O_APPEND, 0644);
		}else
		{
			fd = open(command->in_file, O_RDONLY | O_TRUNC, 0644);
		}
	}
	else if (i_o == 'o')
	{
		if (command->is_append)
		{
			fd = open(command->out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}else
		{
			fd = open(command->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
	}
	return (fd);
}

int	get_pipe_fd(t_pipe *list_pipes, int index, char c)
{
	int 	i;
	t_pipe	*previous;

	previous = NULL;
	i = 0;
	while (list_pipes)
	{
		if (i == index)
		{
			if (c == 'i')
				return (previous->fd[0]);
			else if (c == 'o')
				return (list_pipes->fd[1]);
		}
		previous = list_pipes;
		list_pipes = list_pipes->next;
		i++;
		if (i == index)
		{
			if (list_pipes == NULL)
			{
				if (c == 'i')
					return (previous->fd[0]);
			}
		}
	}
	return (1000);
}

void	assign_input(t_command	*command, t_be_executed	*to_execute)
{
	if (command->in_type == FILE_IO)
	{
		command->fd_in = get_file_fd(command, 'i');
	}
	else if (command->in_type == STDIN_IO)
	{
		command->fd_in = 0;
	}
	else if (command->in_type == PIPE_IO)
	{
		command->fd_in = get_pipe_fd(to_execute->list_pipes, command->index, 'i');
	}
}

void	assign_output(t_command	*command, t_be_executed	*to_execute)
{
	if (command->out_type == FILE_IO)
	{
		command->fd_out = get_file_fd(command, 'o');
	}
	else if (command->out_type == STDIN_IO)
	{
		command->fd_out = 1;
	}
	else if (command->out_type == PIPE_IO)
	{
		command->fd_out = get_pipe_fd(to_execute->list_pipes, command->index, 'o');
	}
}
