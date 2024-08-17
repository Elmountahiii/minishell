/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:30:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 20:32:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handle_heredoc(t_heredoc *heredoc, t_tokens_list **tokens, int list_size)
{
	char	*number;

	if (!heredoc || !tokens || !*tokens)
		return ;
	*tokens = (*tokens)->next;
	if(*tokens && (*tokens)->type == SPACE_TOKEN)
		*tokens = (*tokens)->next;
	if (!*tokens)
		return ;
	number = ft_itoa(list_size);
	heredoc->fd = -1;
	heredoc->file_name = ft_strjoin("/tmp/heredoc", number);
	free(number);
	if ((*tokens)->type == ENV || (*tokens)->type == WORD)
		heredoc->expand_line = true;
	else
		heredoc->expand_line = false;
	if ((*tokens)->type == SINGLE_QUOTE_WORD || (*tokens)->type == DOUBLE_QUOTE_WORD)
		heredoc->dil = ft_remove_quotes((*tokens)->value);
	else
		heredoc->dil = ft_strdup((*tokens)->value);
}

int	ft_check_heredoc(t_tokens_list *tokens)
{
	t_tokens_list	*tmp;
	
	if (!tokens)
		return (0);
	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_heredoc	*ft_create_heredoc(t_tokens_list **tokens,int list_size)
{
	t_heredoc	*heredoc;

	if (!tokens || !*tokens)
		return (NULL);
	if (!ft_check_heredoc(*tokens))
		return (NULL);
	heredoc = ft_calloc(1,sizeof(t_heredoc));
	if (!heredoc)
		return (NULL);
	heredoc->done = true;
	while (*tokens)
	{
		if ((*tokens)->type == HEREDOC)
		{
			ft_handle_heredoc(heredoc, tokens, list_size);
			if (*tokens)
				*tokens = (*tokens)->next;
			break ;
		}
		if ((*tokens)->type == PIPE)
			break ;
		if (*tokens)
			*tokens = (*tokens)->next;
	}
	return (heredoc);
}
