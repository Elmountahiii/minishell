/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:55:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 20:45:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strncpy(str, s1, ft_strlen(s1) + 1);
	ft_strncat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

int	ft_check_when_to_stop(t_tokens_list *tokens)
{
	if (tokens->type == PIPE || tokens->type == SPACE_TOKEN )
		return (1);
	return (0);
}

char	*ft_join_token_value(t_tokens_list **tokens,t_env_list *env_list)
{
	char	*value;
	char	*tmp;
	char	*expand;
	
	if (!tokens || !*tokens)
		return (NULL);
	value = ft_strdup("");
	expand = NULL;
	tmp = NULL;
	while (*tokens)
	{
		if (ft_check_word_valid((*tokens)->type))
		{
			if ((*tokens)->type == SINGLE_QUOTE_WORD || (*tokens)->type == DOUBLE_QUOTE_WORD)
			{
				tmp = ft_remove_quotes((*tokens)->value);		
			}
			else
				tmp = ft_strdup((*tokens)->value);
			if ((*tokens)->type == SINGLE_QUOTE_WORD)
				value = ft_strjoin_free(value, tmp);
			else
			{
				expand = ft_expand(tmp, env_list);
				
				if (ft_strlen(expand) == 0 && (*tokens)->type != DOUBLE_QUOTE_WORD)
				{
					free(expand);
					free(tmp);
					free(value);
					return (NULL);
				}
				value = ft_strjoin_free(value, expand);
				free(expand);
			}
			free(tmp);
		}else
			break;
		if (*tokens)
			*tokens = (*tokens)->next;
	}
	return (value);	
}
