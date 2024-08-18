/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:55:03 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/18 15:20:49 by yel-moun         ###   ########.fr       */
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

void	ft_command_value(char **value, char **expand, char **tmp)
{
	*value = ft_strdup("");
	*expand = NULL;
	*tmp = NULL;
}

char	*ft_free_command_value(char *value, char *expand, char *tmp)
{
	free(value);
	free(expand);
	free(tmp);
	return (NULL);
}

char	*ft_join_token_value(t_tokens_list **tokens, t_env_list *env_list)
{
	char	*value;
	char	*tmp;
	char	*expand;

	if (!tokens || !*tokens)
		return (NULL);
	ft_command_value(&value, &expand, &tmp);
	while (*tokens)
	{
		if (ft_check_word_valid((*tokens)->type))
		{
			tmp = ft_get_command_tmp(tokens);
			expand = ft_expand(tmp, env_list);
			if (ft_get_command_value(&value, &expand, &tmp, tokens))
				return (NULL);
		}
		else
			break ;
		if (*tokens)
			*tokens = (*tokens)->next;
	}
	return (value);
}
