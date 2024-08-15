/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:29:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 13:11:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_heredoc *ft_add_heredoc(t_heredoc **heredoc_list, t_tokens_list *tokens)
{
	t_heredoc		*heredoc;
	t_tokens_list	*tmp;
	int				index;
	int				list_size;

	if (!heredoc_list || !tokens)
		return (NULL);
	tmp = tokens;
	index = 0;
	list_size = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			index ++;
			tmp = tmp->next;
			continue ;
		}
		if (tmp->type == HEREDOC)
		{
			list_size ++;
		heredoc = ft_create_heredoc(&tmp, list_size);
		if (heredoc)
			heredoc->index = index;
		ft_heredoc_addback(heredoc_list, heredoc);	
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (*heredoc_list);
}

