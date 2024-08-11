/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:55:12 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 12:25:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_heredoc	*ft_create_heredoc(t_command *list, char *dil,  t_token_type type)
{
	t_heredoc	*heredoc;
	int			index;

	index = ft_heredoc_size(list) + 1;
	heredoc = ft_calloc(1 ,sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	if (type == SINGLE_QUOTE_WORD || type == DOUBLE_QUOTE_WORD)
		heredoc->dil = ft_remove_quotes(dil);
	else
	{
		heredoc->dil = ft_strjoin(dil, "\n");
	}
	heredoc->file_name = ft_strjoin("/tmp/herdoc", ft_itoa(index));
	ft_open_heredoc(heredoc);
	return (heredoc);
}
