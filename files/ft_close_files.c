/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:06:08 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 10:19:23 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_close_files(t_command	*commands)
{
	t_command	*tmp;
	t_command_files	*tmp_files;
	t_heredoc	*tmp_heredoc;

	tmp = commands;
	while (tmp)
	{
		tmp_files = tmp->files_list;
		while (tmp_files)
		{
			if (tmp_files->fd == -1)
				break;
			tmp_files = tmp_files->next;
		}
		tmp = tmp->next;
	}
	tmp = commands;
	while (tmp)
	{
		tmp_heredoc = tmp->heredoc_list;
		while (tmp_heredoc)
		{
			if (tmp_heredoc->fd == -1)
				break;
			close(tmp_heredoc->fd);
			unlink(tmp_heredoc->file_name);
			tmp_heredoc = tmp_heredoc->next;
		}
		tmp = tmp->next;
	}
}
