/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:46:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 23:28:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_expandable(t_tokens_list *token)
{
	if (!token)
		return (0);
	if (token->type == ENV && ft_strlen(token->value) > 1)
			return (1);
	if (token->type == WORD || token->type == DOUBLE_QUOTE_WORD)
		return (1);
	return (0);
}

int	ft_keys_count(char *str, t_token_type type)
{
	int	i;
	int	count;
	char *value;

	i = 0;
	count = 0;
	if (type == DOUBLE_QUOTE_WORD)
	value = ft_remove_quotes(str);
	else
		value = ft_strdup(str);
	while (value && value[i])
	{
		if (value[i] == '$' && value[i + 1])
			count++;
		i++;
	}
	free(value);
	return (count);
}
char **ft_split_keys(char *str , t_token_type type)
{
	char	**keys;
	char	*value;
	int		i;
	int 	index;

	keys = ft_calloc(ft_keys_count(str, type) + 1, sizeof(char *));
	if (!keys)
		return (NULL);
	if (type == DOUBLE_QUOTE_WORD)
		value = ft_remove_quotes(str);
	else
		value = ft_strdup(str);
	i = 0;
	index = 0;
	while (value && value[i])
	{
		if (value[i] == '$' && value[i + 1] && !ft_is_env_char(value[i + 1]))
		{
			keys[index] = ft_extract_key(&value[i + 1]);
			// printf("key[%d]: %s\n", index ,keys[index]);
			i += ft_strlen(keys[index]);
			index++;
		}
		else
			i++;
	}
	free(value);
	keys[index] = NULL;
	return (keys);
}

void	ft_tokens_expand(t_tokens_list *tokens_list, t_env_list *env_list)
{
	(void)env_list;
	char **keys;

	keys = NULL;
	while (tokens_list)
	{
		if (ft_is_expandable(tokens_list))
		{
			// printf("count: %d\n", ft_keys_count(tokens_list->value, tokens_list->type));
			keys = ft_split_keys(tokens_list->value, tokens_list->type);
			ft_link_key_value(tokens_list->value, keys, env_list);
			
		}
		tokens_list = tokens_list->next;
	}
}