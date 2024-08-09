/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:21:56 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 19:27:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_open(t_command_files *file)
{
	int	fd;

	fd = -1;
	if (file->type == REDIRECTION_IN)
		fd = open(file->name, O_RDONLY);
	else if (file->type == REDIRECTION_OUT)
		fd = open(file->name, O_CREAT | O_RDWR | O_TRUNC, 0666);
	else if (file->type == APPEND)
		fd = open(file->name, O_CREAT | O_RDWR | O_APPEND, 0666);
	return (fd);
}

void	ft_open_files(t_command *command)
{
	t_command	*commands_tmp;
	t_command_files	*files_tmp;

	if (!command)
		return ;
	commands_tmp = command;
	files_tmp = commands_tmp->files_list;	
	while (commands_tmp)
	{
		files_tmp = commands_tmp->files_list;
		while (files_tmp)
		{
			files_tmp->fd = ft_open(files_tmp);
			if (files_tmp->fd == -1)
				break ;
			files_tmp = files_tmp->next;
		}
		commands_tmp = commands_tmp->next;
	}
}
