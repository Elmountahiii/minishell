/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:09:06 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 14:46:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_value(char *key, t_env_list *env)
{
	if (!key)
		return (ft_strdup("$"));
	if (key[0] == '?')
		return (ft_itoa(g_exit_status));
	if (key[0] == '$' && ft_strlen(key) == 1)
		return (ft_strdup("$"));
	if (key[0] == '@' || ft_isdigit(key[0]))
	{
		if (ft_strlen(key) == 1 && key[0] == '@')
			return (ft_strdup("@"));
		return (ft_strdup(key + 1));
	}
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
	int	index;

	ft_init_value(&i, &len, &index);
	while (str[i])
	{
		if (str[i] == '$' )
		{
			i++;
			if (str[i] && str[i] == '?' && i++)
				ft_count_1(&len, &index);
			else
			{
				ft_count_2(keys[index], env, &len);
				if (str[i])
					i += ft_strlen(keys[index++]);
			}
		}
		else
			ft_increment(&i, &len);
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
	free(value);
	return (i);
}

void	process_expansion(char *original, char **keys,
	char *buffer, t_env_list *env)
{
	int		i;
	int		index;
	int		j;

	i = 0;
	index = 0;
	j = 0;
	while (original[i])
	{
		if (original[i] == '$')
		{
			i++;
			if (original[i] && original[i] == '?')
				ft_handle_expand_1(buffer, &i, &j, &index);
			else
			{
				j = ft_join_key(buffer, ft_get_value(keys[index], env), j);
				if (original[i])
					i += ft_strlen(keys[index++]);
			}
		}
		else
			buffer[j++] = original[i++];
	}
	buffer[j] = '\0';
}

char	*ft_expand(char *original, t_env_list *env)
{
	char	**keys;
	char	*expanded;

	if (!original)
		return (NULL);
	keys = ft_split_keys(original);
	expanded = ft_calloc(ft_count_expand_len(original, keys, env) + 1,
			sizeof(char));
	if (!expanded)
		return (NULL);
	process_expansion(original, keys, expanded, env);
	ft_clean_array(keys);
	return (expanded);
}
