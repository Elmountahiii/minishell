/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:09:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 23:59:41 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_value(char *key, t_env_list *env)
{
	if (!key)
		return (NULL);
	if (key[0] == '?')
		return (ft_itoa(exit_status));
	while (env)
	{
		if (!ft_strcmp(key, env->key))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

int	ft_count_expand_len(char *str, char **keys, t_env_list *env)
{
	int	i;
	int	len;
	int index;
	
	if (!str)
		return (0);
	i = 0;
	len = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			i++;
			while (str[i] && !ft_is_env_char(str[i]))
				i++;
			len += ft_strlen(ft_get_value(ft_extract_key(keys[index++]), env));
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

int	ft_join_key(char *buffer, char *value, int index)
{
	int	i;
	int	j;

	i = index;
	j = 0;
	while (value[j])
	{
		buffer[i] = value[j];
		i++;
		j++;
	}
	return (i);
}


char	*ft_link_key_value(char *str, char **keys ,t_env_list *env_list)
{
	char	*expand;
	int		i;
	int		index;
	int 	j;
	
	//printf("the len is %d\n", ft_count_expand_len(str, keys, env_list));
	expand = ft_calloc(ft_count_expand_len(str, keys, env_list) + 1, sizeof(char));
	if (!expand)
		return (NULL);
	i = 0;
	index = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			//printf()
			i++;
			while (str[i] && !ft_is_env_char(str[i]))
				i++;
			j = ft_join_key(&expand[j], ft_get_value(ft_extract_key(keys[index++]), env_list), j);
		}else
		{
			expand[j] = str[i];
			j++;
			i++;
		}
	}
	expand[j] = '\0';
	printf("expand: %s\n", expand);
	return (NULL);
}
