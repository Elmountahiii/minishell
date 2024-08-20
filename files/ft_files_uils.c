/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_uils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:36:00 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/20 16:44:57 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	ft_check_expandable(t_ttype type)
{
	if (type == WORD
		|| type == SINGLE_QUOTE_WORD
		|| type == DOUBLE_QUOTE_WORD)
		return (1);
	return (0);
}

char	*ft_get_value_name(char *value ,t_tokens_list **tokens)
{
	char *value;
	
	if (!tokens || !*tokens)
		return (NULL);
	
}

char	*ft_get_file_name(t_tokens_list **tokens, t_env_list *env_list)
{
	char	*value;
	char	*tmp;

	if (!tokens || !*tokens)
		return (NULL);
	value = NULL;
	while (*tokens)
	{
		if (ft_check_word_valid((*tokens)->type))
		{
			if (ft_check_expandable((*tokens)->type))
			{
				
			}
		}
		else
			break ;
	}
	
	return (value);
}
