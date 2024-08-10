/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:47:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 15:08:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	listen_for_heredoc(t_heredoc *heredoc)
{
	char	*line;

	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_strncmp(line, heredoc->dil, ft_strlen(heredoc->dil)))
		{
			free(line);
			break ;
		}
		write(heredoc->fd, line, ft_strlen(line));
		free(line);
	}
}


void	ft_fill_heredoc(t_command *command)
{
	t_heredoc	*tmp;
	pid_t		pid;

	if (!command || !command->heredoc_list)
		return ;
	tmp = command->heredoc_list;
	while (tmp)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return ;
		}
		if (pid == 0)
		{
			listen_for_heredoc(tmp);
			exit(0);
		}
		waitpid(pid, NULL, 0);
		close(tmp->fd);
		tmp->fd = open(tmp->file_name, O_RDONLY);
		tmp = tmp->next;
	}
}
