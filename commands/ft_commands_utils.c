/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:55:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 14:45:04 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	strncpy(str, s1, ft_strlen(s1) + 1);
	strncat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
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
	
	if (!tokens || !*tokens)
		return (NULL);
	value = strdup("");
	tmp = NULL;
	while (*tokens)
	{
		if (ft_check_word_valid((*tokens)->type))
		{
			if ((*tokens)->type == SINGLE_QUOTE_WORD || (*tokens)->type == DOUBLE_QUOTE_WORD)
				tmp = strdup(ft_remove_quotes((*tokens)->value));
			else
				tmp = strdup((*tokens)->value);
			value = ft_strjoin_free(value, ft_expand(tmp, env_list));
			free(tmp);
		}else
			break;
		if (*tokens)
			*tokens = (*tokens)->next;
	}
	return (value);	
}
