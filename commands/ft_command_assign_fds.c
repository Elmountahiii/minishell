/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_assign_fds.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:17:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 11:10:55 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_in_files(t_command *command, t_command_files *selected_file)
{
	command->in_file = ft_strdup(selected_file->file_name);
	command->fd_in = selected_file->fd;
	command->is_ambiguous = selected_file->is_ambiguous;
	if (selected_file->is_ambiguous)
	{
		free(command->ambiguous_name);
		command->ambiguous_name = ft_strdup(selected_file->ambiguous_name);
	}
}

void	ft_add_out_files(t_command *command, t_command_files *selected_file)
{
	command->out_file = ft_strdup(selected_file->file_name);
	command->fd_out = selected_file->fd;
	command->is_ambiguous = selected_file->is_ambiguous;
	if (selected_file->is_ambiguous)
	{
		free(command->ambiguous_name);
		command->ambiguous_name = ft_strdup(selected_file->ambiguous_name);
	}
}

void	ft_assign_from_heredoc(t_command *command, t_heredoc *heredoc_list)
{
	t_heredoc	*h_tmp;
	t_heredoc	*selected_heredoc;

	if (!command || !heredoc_list)
		return ;
	h_tmp = heredoc_list;
	selected_heredoc = NULL;
	while (h_tmp)
	{
		
		if (h_tmp->index == command->index)
			selected_heredoc = h_tmp;
		h_tmp = h_tmp->next;
	}
	if (selected_heredoc)
	{
		command->in_file = ft_strdup(selected_heredoc->file_name);
		command->fd_in = selected_heredoc->fd;
	}
}

void	ft_assign_from_files(t_command *command,
	t_command_files *files, t_token_type type)
{
	t_command_files	*f_tmp;
	t_command_files	*selected_file;

	if (!command || !files)
		return ;
	f_tmp = files;
	selected_file = NULL;
	while (f_tmp)
	{
		if (f_tmp->index == command->index && f_tmp->fd == -1)
		{
			selected_file = f_tmp;
			break ;
		}
		if (f_tmp->index == command->index && f_tmp->type == type)
			selected_file = f_tmp;
		f_tmp = f_tmp->next;
	}
	if (selected_file && type == REDIRECTION_IN)
		ft_add_in_files(command, selected_file);
	else if (selected_file && (type == REDIRECTION_OUT || type == APPEND))
		ft_add_out_files(command, selected_file);
}

void	ft_command_assign_fds(t_command *command,
	t_command_files *files_list, t_heredoc *heredoc_list)
{
	t_command	*c_tmp;

	if (!command)
		return ;
	c_tmp = command;
	while (c_tmp)
	{
		if (c_tmp->in_type == FILE_IO)
		{
			if (c_tmp->is_heredoc)
				ft_assign_from_heredoc(c_tmp, heredoc_list);
			else
				ft_assign_from_files(c_tmp, files_list, REDIRECTION_IN);
		}
		if (c_tmp->out_type == FILE_IO)
		{
			if (c_tmp->is_append)
				ft_assign_from_files(c_tmp, files_list, APPEND);
			else
				ft_assign_from_files(c_tmp, files_list, REDIRECTION_OUT);
		}
		c_tmp = c_tmp->next;
	}
	
}
