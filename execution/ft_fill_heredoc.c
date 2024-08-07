/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:47:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/07 12:38:42 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_fill_heredoc(t_command *command)
{
	char		*line;
	t_heredoc	*tmp;

	if (!command || !command->heredoc_list)
		return ;
	tmp = command->heredoc_list;
	while (tmp)
	{
		while (1)
		{
			write(1, "> ", 2);
			line = get_next_line(0);
			if (!line)
				break ;
		if (!ft_strncmp(line, tmp->dil, ft_strlen(tmp->dil)))
		{
			free(line);
			break ;
		}
		write(tmp->fd, line, ft_strlen(line));
		free(line);
		}
		 close(tmp->fd);
		 tmp->fd = open(tmp->file_name, O_RDONLY);
		tmp = tmp->next;
	}
}
