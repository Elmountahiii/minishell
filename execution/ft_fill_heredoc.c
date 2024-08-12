/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:47:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 16:23:07 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(11);
}

void	listen_for_heredoc(t_heredoc *heredoc)
{
	char	*line;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line)
		{
			break ;
		}
		if (!ft_strncmp(line, heredoc->dil, ft_strlen(line)))
		{
			free(line);
			break ;
		}
		write(heredoc->fd, line, ft_strlen(line));
		free(line);
	}
	exit(0);
}

int	ft_fill_heredoc(t_command *command)
{
	t_heredoc	*tmp;
	pid_t		pid;
	int			status;
	if (!command || !command->heredoc_list)
		return (0);
	tmp = command->heredoc_list;
	signal(SIGINT, SIG_IGN);
	while (tmp)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (2);
		}
		if (pid == 0)
		{
			listen_for_heredoc(tmp);
			exit(0);
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 11)
				return (1);
		}
		close(tmp->fd);
		tmp->fd = open(tmp->file_name, O_RDONLY);
		tmp = tmp->next;
	}
	signal(SIGINT, sig_handler);
	return (0);
}
