/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_until_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:01:16 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/01 12:41:06 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_valid_word(t_tokens_list *t)
{
	if (t->type == WORD || t->type == SINGLE_QUOTE_WORD
		|| t->type == DOUBLE_QUOTE_WORD || t->type == ENV)
		return (1);
	return (0);
}

char	*ft_custom_strjoin(char *old, t_tokens_list *token)
{
	char	*new_str;
	int		i;
	int		j;

	if (token->type == WORD)
		return (ft_strjoin(old, token->value));
	new_str = ft_calloc(ft_strlen(old) + ft_strlen(token->value) + 1,
			sizeof(char));
	if (!new_str)
		return (NULL);
	i = ft_strcpy(new_str, old);
	j = 0;
	while (token->value[j])
	{
		if (token->value[j] == token->value[0])
		{
			j++;
			continue ;
		}
		new_str[i] = token->value[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return ( new_str);
}

char	*ft_join(char *old, t_tokens_list **tokens)
{
	char	*new_str;
	char	*tmp;

	new_str = ft_strdup(old);
	free(old);
	tmp = NULL;
	while (*tokens && ft_is_valid_word(*tokens))
	{
		tmp = new_str;
		new_str = ft_custom_strjoin(new_str, (*tokens));
		free(tmp);
		*tokens = (*tokens)->next;
	}
	return (new_str);
}
