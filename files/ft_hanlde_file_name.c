/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hanlde_file_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:04:27 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 19:16:36 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_valid_file_name(t_token_type type)
{
	if (type == WORD || type == DOUBLE_QUOTE_WORD || type == SINGLE_QUOTE_WORD || type == ENV)
		return (1);
	return (0);
}

char	*ft_handle_file_name(t_tokens_list **tokens)
{
	char	*file_name;
	char	*tmp;
	
	if (!tokens || !*tokens)
		return (NULL);
	file_name = NULL;
	tmp = NULL;
	while (*tokens && ft_is_valid_file_name((*tokens)->type))
	{
		tmp = file_name;
		if ((*tokens)->type == SINGLE_QUOTE_WORD || (*tokens)->type == DOUBLE_QUOTE_WORD)
			file_name = ft_strjoin(file_name, ft_remove_quotes((*tokens)->value));
		else
			file_name = ft_strjoin(file_name, (*tokens)->value);
		*tokens = (*tokens)->next;
		free(tmp);
	}
	return (file_name);	
}