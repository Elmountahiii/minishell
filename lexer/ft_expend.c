/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:22:22 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/05 13:14:20 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_env(char *str)
{
	int	i;
	

	if (str &&  ft_strlen(str) == 3 )
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_token_expandable(t_tokens_list *token)
{
	if (!token)
		return (0);
	if (token->type == ENV && ft_strlen(token->value) > 1)
		return (1);
	if (token->type == DOUBLE_QUOTE_WORD)
	{
		if (ft_is_env(token->value))
			return (1);
	}
	return (0);
}

int	ft_count_keys(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '$')
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

char	**ft_extract_keys(char *str)
{
	char	**keys;
	int		i;
	int		index;
	
	keys = ft_calloc(ft_count_keys(str) + 1, sizeof(char *));
	i = 0;
	index = 0;
	if (!keys)
		return (NULL);
	while (str && str[i])
	{
		if (str[i] == '$')
		{
			i++;
			keys[index] = ft_get_key(str, i);
			index++;
		}
		i++;
	}
	keys[index] = NULL;
	return (keys);
}

void	ft_expend_tokens(t_tokens_list *token, t_env_list *env)
{
	char **keys;

	keys = NULL;
	while (token)
	{
		if (ft_is_token_expandable(token))
		{
			keys = ft_extract_keys(token->value);
			token->value = ft_expand(token->value, keys, env);
		}
		// free keys
		token = token->next;
	}
}
