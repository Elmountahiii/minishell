/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_in_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:17:38 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/28 11:26:03 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if(!s1 || !s2)
		return (1);
	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int get_file_fd(t_list_files 	*list_of_files, char *file_name)
{
	while (list_of_files)
	{
		if (ft_strcmp(list_of_files->name, file_name) == 0)
			return (list_of_files->fd);
		list_of_files = list_of_files->next;
	}
	return (0);
}

void assign_in(t_command *command_list, t_list_files *list_of_files, t_pipe *list_pipes)
{
	if (command_list->in_type == FILE_IO)
	{
		command_list->fd_in = get_file_fd(list_of_files, command_list->in_file);
	}
	else if (command_list->in_type == STDIN_IO)
	{
		command_list->fd_in = 0;
	}
	else if (command_list->in_type == PIPE_IO)
	{
		command_list->fd_in = get_pipe_fd(list_pipes, command_list->index, 'i');
	}
}

void assign_out(t_command *command_list, t_list_files *list_of_files, t_pipe *list_pipes)
{
	if (command_list->out_type == FILE_IO)
	{
		command_list->fd_out = get_file_fd(list_of_files, command_list->out_file);
	}
	else if (command_list->out_type == STDOUT_IO)
	{
		command_list->fd_out = 1;
	}
	else if (command_list->out_type == PIPE_IO)
	{
		command_list->fd_out = get_pipe_fd(list_pipes, command_list->index, 'o');
	}
}
