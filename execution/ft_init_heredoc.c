/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:21:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 15:01:04 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_heredoc(t_command *command)
{
	t_command	*tmp;
	t_heredoc	*heredoc;
	
	if (!command)
		return ;
	tmp = command;
	while (tmp)
	{
		 ft_fill_heredoc(tmp);
		tmp = tmp->next;
	}
	tmp = command;
	while (tmp)
	{
		heredoc = tmp->heredoc_list;
		if (heredoc && tmp->is_heredoc)
		{
			while (heredoc->next)
				heredoc = heredoc->next;
			tmp->fd_in = heredoc->fd;
			tmp->in_file = heredoc->file_name;
		}
		tmp = tmp->next;
	}
}
