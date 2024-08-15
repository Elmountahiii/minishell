/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:09:06 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 13:44:25 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_value(char *key, t_env_list *env)
{
	if (!key)
		return (strdup("$"));
	if (key[0] == '?')
		return (ft_itoa(0));
	if (key[0] == '$' && ft_strlen(key) == 1)
		return (strdup("$"));
	if (key[0] == '@' || ft_isdigit(key[0]))
	{
		if (ft_strlen(key) == 1 && key[0] == '@')
			return (strdup("@"));
		return (strdup(key + 1));	
	}
	while (env)
	{
		if (!strcmp(key, env->key))
			return (strdup(env->value));
		env = env->next;
	}
	return (NULL);
}


int	ft_count_expand_len(char *str, char **keys, t_env_list *env)
{
	int	i;
	int	len;
	int index;
	char *tmp;
	
	i = 0;
	len = 0;
	index = 0;
	tmp = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] && str[i] == '?')
			{
				i++;
				tmp = ft_itoa(0);
				len += ft_strlen(tmp);
				index++;
			}
			else
			{
			tmp = ft_get_value(keys[index], env);
			len += ft_strlen(tmp);
			if(str[i])
				i += ft_strlen(keys[index++]);
			}
			free(tmp);
			tmp = NULL;
		}
		else
		{
			len++;
			i++;
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
	if (!value || !buffer)
		return (i);
	
	while (value[j])
	{
		buffer[i] = value[j];
		i++;
		j++;
	}
	return (i);
}


char	*ft_expand(char *original, t_env_list *env)
{
	char	**keys;
	char	*expanded;
	int		i;
	int		index;
	int 	j;
	char *tmp;

	if (!original)
		return (NULL);
	keys = ft_split_keys(original);
	// ft_print_array(keys);
	// printf("final len : %d\n", ft_count_expand_len(original, keys, env));
	// return (NULL);
	expanded = calloc(ft_count_expand_len(original, keys, env) + 1, sizeof(char));
	if (!expanded)
		return (NULL);
	i = 0;
	index = 0;
	j = 0;
	tmp = NULL;
	
	while (original[i])
	{
		if (original[i] == '$')
		{
			i++;
			if (original[i] && original[i] == '?')
			{
				tmp = ft_itoa(0);
	
				j = ft_join_key(expanded, tmp, j);
				i++;
				index++;
			}
			else
			{
				tmp = ft_get_value(keys[index], env);
				
				j = ft_join_key(expanded, tmp, j);
				if(original[i])
					i += ft_strlen(keys[index++]);
			}
			free(tmp);
			tmp = NULL;
		}else
		{
			expanded[j] = original[i];
			j++;
			i++;
		}
	}
	expanded[j] = '\0';
	return (expanded);
}