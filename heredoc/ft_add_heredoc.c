/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:29:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/18 12:16:00 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_tokens(t_tokens_list *tokens,
	t_heredoc **heredoc_list, int *index, int *list_size)
{
	t_tokens_list	*tmp;
	t_heredoc		*heredoc;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			(*index)++;
			tmp = tmp->next;
			continue ;
		}
		if (tmp->type == HEREDOC)
		{
			(*list_size)++;
			heredoc = ft_create_heredoc(&tmp, *list_size);
			if (heredoc)
				heredoc->index = *index;
			ft_heredoc_addback(heredoc_list, heredoc);
		}
		if (tmp)
			tmp = tmp->next;
	}
}

t_heredoc	*ft_add_heredoc(t_heredoc **heredoc_list, t_tokens_list *tokens)
{
	int	index;
	int	list_size;

	if (!heredoc_list || !tokens)
		return (NULL);
	index = 0;
	list_size = 0;
	process_tokens(tokens, heredoc_list, &index, &list_size);
	return (*heredoc_list);
}
