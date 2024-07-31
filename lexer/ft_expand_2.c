/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:47:39 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_append_char(char *str, char c)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_strdup(str);
	free(str);
	str = calloc(ft_strlen(new_str) + 2, sizeof(char));
	if (!str)
		return (0);
	while (new_str[i])
	{
		str[i] = new_str[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(new_str);
	return (str);
}

char	*ft_get_key(char *str, int i)
{
	char	*key;

	key = ft_strdup("");
	while (str[i] && is_valid_expand(str[i]))
	{
		key = ft_append_char(key, str[i]);
		i++;
	}
	return (key);
}

int is_valid_expand(char c)
{
	if (c != ' ' && c != '$' && c != '\'' && c != '\"')
		return (1);
	return (0);
}

char	*ft_expand(char *value, char **keys, char **env)
{
	int	i;
	int j;
	int	index;
	

	i = 0;
	j = 0;
	index = 0;
	//printf("aloc = %d\n", ft_count_expand_alloc(value, env, keys) + 1);
	char *new_value = calloc(ft_count_expand_alloc(value, env, keys) + 1, sizeof(char));
	if (!new_value)
		return (NULL);
	while (value && value[i])
	{
		if (value[i] == '$')
		{
			i++;
			while (value[i] && is_valid_expand(value[i]))
				i++;
			//printf("new value = %s\n", new_value);
			//printf("key = %s\n", keys[index]);
			//printf("value = %s\n", ft_get_key_value(keys[index], env));
			new_value = ft_strjoin(new_value, ft_get_key_value(keys[index], env));
			//printf("new new value = %s\n", new_value);
			j = ft_strlen(new_value);
			//printf("j = %d\n", j);
			index++;
			
		}else
			new_value[j++] = value[i++];
	}
	//printf("j = %d\n", j);
	new_value[j] = '\0';
	return (new_value);
}
