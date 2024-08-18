/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:15:15 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/18 13:58:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_env_char(char c)
{
	if (c == ' ' || c == '@' || c == '-'
		|| c == '.' || c == '$' || c == '\''
		|| c == '\"')
		return (1);
	return (0);
}

char	*ft_handel_dollar_sign(char *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	new_str = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[i] = str[i];
	i ++;
	if (str[i] == '@')
	{
		new_str[i] = str[i];
		i ++;
	}
	while (str[i] && !ft_is_env_char(str[i]))
	{
		new_str[i] = str[i];
		i ++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_count_len(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '@')
		i++;
	while (str[i] && !ft_is_env_char(str[i]))
		i++;
	return (i);
}

char	*ft_extract_key(char *str)
{
	char	*key;
	int		i;

	if (!str)
		return (NULL);
	if (str[0] == '$')
		return (ft_handel_dollar_sign(str));
	if (ft_count_len(str) == 0)
		return (NULL);
	key = ft_calloc(ft_count_len(str) + 1, sizeof(char));
	if (!key)
		return (NULL);
	if (str[0] == '@')
	{
		key[0] = '@';
		i = 1;
	}
	else
		i = 0;
	while (str[i] && !ft_is_env_char(str[i]))
	{
		key[i] = str[i];
		i++;
	}
	return (key[i] = '\0', key);
}
