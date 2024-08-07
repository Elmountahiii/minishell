/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:06:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/07 12:03:26 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_heredoc_size(t_command *commands)
{
	int			size;
	t_command	*tmp;
	t_heredoc	*heredoc;

	size = 0;
	tmp = commands;
	while (tmp)
	{
		heredoc = tmp->heredoc_list;
		while (heredoc)
		{
			size++;
			heredoc = heredoc->next;
		}
		tmp = tmp->next;
	}
	return (size);
}
