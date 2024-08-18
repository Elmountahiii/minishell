/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/18 12:54:53 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(11);
}

void	ft_heredoc_lisente(t_heredoc *heredoc_list, t_env_list *env_list)
{
	char	*line;
	char	*tmp_expand;

	if (!heredoc_list)
		return ;
	line = NULL;
	tmp_expand = NULL;
	heredoc_list->fd = open(heredoc_list->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (heredoc_list->fd < 0)
		return ;
	signal(SIGINT, handle_sigint);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, heredoc_list->dil) == 0)
		{
			free(line);
			break ;
		}
		if (heredoc_list->expand_line)
		{
			tmp_expand = ft_expand(line, env_list);
		}else
			tmp_expand = ft_strdup(line);
		write(heredoc_list->fd, tmp_expand, ft_strlen(tmp_expand));
		write(heredoc_list->fd, "\n", 1);
		free(line);
		free(tmp_expand);
		tmp_expand = NULL;
	}
	exit(0);
}

int	ft_open_heredoc(t_heredoc *heredoc_list, t_env_list *env_list)
{
	t_heredoc	*tmp;
	pid_t		pid;
	int			status;

	if (!heredoc_list)
		return (0);
	tmp = heredoc_list;
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
			ft_heredoc_lisente(tmp, env_list);
			exit(0);
		}
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 11)
			{
				tmp->done = false;
				return (1);
			}
		}
		close(tmp->fd);
		tmp->fd = open(tmp->file_name, O_RDONLY);
		tmp = tmp->next;
	}
	signal(SIGINT, sig_handler);
	return (0);
}
