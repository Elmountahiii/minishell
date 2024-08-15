/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:21:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/12 15:43:16 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_init_heredoc(t_command *command)
{
	t_command	*tmp;
	t_heredoc	*heredoc;
	
	if (!command)
		return (0);
	tmp = command;
	while (tmp)
	{
		// ft_fill_heredoc returns 2 when fork fails
		// return 1 when ctrl c 
		if (ft_fill_heredoc(tmp))
			return (1);
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
			tmp->in_file = ft_strdup(heredoc->file_name);
			//system("leaks minishell");
		}
		tmp = tmp->next;
	}
	return (0);
}
