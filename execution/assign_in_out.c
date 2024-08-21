/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:36:57 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 12:19:41 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prror_exit(char *str, char *file)
{
	char	*message;

	message = ft_strjoin(str, file);
	perror(message);
	free(message);
	g_exit_status = 1;
}

int	get_file_fd(t_command *command, char i_o)
{
	int	fd;

	fd = 1;
	if (i_o == 'i')
	{
		assign_fd_heredc(&fd, command);
	}
	else if (i_o == 'o')
	{
		assign_fd_append(&fd, command);
	}
	return (fd);
}

int	get_pipe_fd(t_pipe *list_pipes, int index, char c)
{
	int		i;
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
		increament_elems(&list_pipes, &i, &previous);
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

void	assign_input(t_command *command, t_be_executed *to_execute)
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
		command->fd_in = get_pipe_fd(to_execute->list_pipes, command->index,
				'i');
	}
}

void	assign_output(t_command *command, t_be_executed *to_execute)
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
		command->fd_out = get_pipe_fd(to_execute->list_pipes, command->index,
				'o');
	}
}
