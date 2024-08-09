/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:47:39 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/08 22:31:40 by yel-moun         ###   ########.fr       */
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


int	expand_join(char *new_value, char *value, int index)
{
	int	i;

	i = 0;
	if (!value)
		return (index);
	//printf("value = %s\n", value);
	while(value[i])
	{
		new_value[index] = value[i];
		i++;
		index++;
	}
	return (index);
}

char *find_value(char * key ,t_env_list *env)
{
	if (key && !key[0])
		return ("$");
	while (env)
	{
		if (key && key[0] == '?')
		{
			//printf("key = %s value = %s \n", key, ft_itoa(exit_status));
			return (ft_itoa(exit_status));
		}
		if (ft_strcmp(env->key, key) == 0)
		{
			//printf("key = %s value = %s \n", key, env->value);
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}

char	*ft_expand(char *value, char **keys, t_env_list *env)
{
	int	i;
	int j;
	int	index;
	
	i = 0;
	j = 0;
	index = 0;

	char *new_value = ft_calloc(ft_count_expand_alloc(value, env, keys) + 1, sizeof(char));
	if (!new_value)
		return (NULL);
	
	while (value && value[i])
	{
		if (value[i] == '$')
		{
			i++;
			if (value[i] == '?')
			{
				j = expand_join(new_value, find_value("?",env), j);
				index++;
				i++;
				continue ;
			}
			while (value[i] && is_valid_expand(value[i]))
				i++;
			j = expand_join(new_value, find_value(keys[index],env), j);
			index++;			
		}else
			new_value[j++] = value[i++];
	}
	new_value[j] = '\0';
	return (new_value);
}
