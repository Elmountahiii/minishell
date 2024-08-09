/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:13:40 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 19:46:27 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_select_out_file(t_command *command)
{
	t_command_files	*selected_file;

	if (!command)
		return ;
	selected_file = ft_correct_out_file(command->files_list);
	if (selected_file)
	{
		command->fd_out = selected_file->fd;
		command->out_file = selected_file->name;
	}
}

void	ft_select_in_file(t_command *command)
{
	t_command_files	*selected_file;
	t_heredoc		*selected_heredoc;

	if (!command)
		return ;
	if (command->is_heredoc)
	{
		selected_heredoc = ft_heredoc_last(command->heredoc_list);
		if (selected_heredoc)
		{
			command->fd_in = selected_heredoc->fd;
			command->in_file = selected_heredoc->file_name;
		}
	}
	else
	{
		selected_file = ft_correct_in_file(command->files_list);
		if (selected_file)
		{
			command->fd_in = selected_file->fd;
			command->in_file = selected_file->name;
		}
	}
}

void	ft_select_files(t_command *command)
{
	t_command	*commands_tmp;

	if (!command)
		return ;
	commands_tmp = command;
	while (commands_tmp)
	{
		ft_select_out_file(commands_tmp);
		ft_select_in_file(commands_tmp);
		commands_tmp = commands_tmp->next;
	}
}