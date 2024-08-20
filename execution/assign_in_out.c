/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:36:57 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 13:07:11 by yel-moun         ###   ########.fr       */
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
			if (fd == -1)
			{
				perror(ft_strjoin("minishell: ", command->in_file));
				// exit(1);
			}
		}else
		{
			fd = open(command->in_file, O_RDONLY, 0644);
			if (fd == -1)
			{
				perror(ft_strjoin("minishell: ", command->in_file));
				// exit(1);
			}
		}
	}
	else if (i_o == 'o')
	{
		if (command->is_append)
		{
			fd = open(command->out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (fd == -1)
			{
				perror(ft_strjoin("minishell: ", command->out_file));
				exit(1);
			}
		}else
		{
			fd = open(command->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1)
			{
				perror(ft_strjoin("minishell: ", command->out_file));
				exit(1);
			}
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

	if (command->in_type == FILE_IO && command->is_heredoc)
	{
		return ;
	}
	else if (command->in_type == FILE_IO)
	{
		command->fd_in = get_file_fd(command, 'i');
	}
	else if (command->in_type == STDIN_IO)
	{
		command->fd_in = STDIN_FILENO;
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
		command->fd_out = STDOUT_FILENO;
	}
	else if (command->out_type == PIPE_IO)
	{
		command->fd_out = get_pipe_fd(to_execute->list_pipes, command->index, 'o');
	}
}
