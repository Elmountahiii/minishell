/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:52 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 14:34:58 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(11);
}

void	ft_write_to_file(int fd, char *line, char *tmp_expand)
{
	write(fd, tmp_expand, ft_strlen(tmp_expand));
	write(fd, "\n", 1);
	free(line);
	free(tmp_expand);
	tmp_expand = NULL;
}

int	ft_open_that_fd(t_heredoc *heredoc_list, char **line, char **tmp_expand)
{
	if (!heredoc_list)
		return (1);
	*line = NULL;
	*tmp_expand = NULL;
	heredoc_list->fd = open(heredoc_list->file_name, O_CREAT
			| O_WRONLY | O_TRUNC, 0644);
	if (heredoc_list->fd < 0)
	{
		perror("minishell: open");
		return (1);
	}
	return (0);
}

void	ft_heredoc_lisente(t_heredoc *heredoc_list, t_env_list *env_list)
{
	char	*line;
	char	*tmp_expand;

	if (ft_open_that_fd(heredoc_list, &line, &tmp_expand))
		exit(1);
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
			tmp_expand = ft_expand(line, env_list);
		else
			tmp_expand = ft_strdup(line);
		ft_write_to_file(heredoc_list->fd, line, tmp_expand);
	}
	exit(0);
}

int	ft_open_heredoc(t_heredoc *heredoc_list, t_env_list *env_list)
{
	t_heredoc	*tmp;
	pid_t		pid;
	int			status;

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
			ft_heredoc_lisente(tmp, env_list);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 11 || WEXITSTATUS(status) == 1)
				return (1);
		}
		ft_re_open(&tmp);
	}
	return (signal(SIGINT, sig_handler), 0);
}
