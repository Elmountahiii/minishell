/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:47:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/06 11:42:07 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_fill_heredoc(t_command *command)
{
	char	*line;

	if (command->fd_in < 0)
		return ;
	command->dil = ft_strjoin(command->dil, "\n");
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_strncmp(line, command->dil, ft_strlen(command->dil)))
		{
			free(line);
			break ;
		}
		write(command->fd_in, line, ft_strlen(line));
		free(line);
	}
	close(command->fd_in);
	command->fd_in = open(command->in_file, O_RDONLY);
}
