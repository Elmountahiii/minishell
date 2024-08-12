/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_key_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 23:09:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/12 16:26:45 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_value(char *key, t_env_list *env)
{
	if (!key)
		return (ft_strdup("$"));
	if (key[0] == '?')
		return (ft_itoa(exit_status));
	// if the key is just $ return $
	
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


int	ft_do_count(char *str, char **keys, t_env_list *env, int len)
{
	if (str[0] == '$')
	{
		if (str[1] == '$' || str[1] == '@')
			return (1);
		if (str[1] == '?')
			return (ft_strlen(ft_itoa(exit_status)));
		return (ft_strlen(ft_get_value(ft_extract_key(keys[len]), env)));
	}
	return (0);
}

int	ft_count_expand_len(char *str, char **keys, t_env_list *env)
{
	int	i;
	int	len;
	int index;
	(void)keys;
	(void)env;
	i = 0;
	len = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] && (str[i] == '$'))
			{
				len += ft_strlen(ft_get_value(keys[index], env));
				i += ft_strlen(keys[index++]);
			}
			else if (str[i] && str[i] == '?')
			{
				i++;
				len += ft_strlen(ft_itoa(exit_status));
				index++;
			}
			else
			{
				len += ft_strlen(ft_get_value(keys[index], env));
				i += ft_strlen(keys[index++]);
			}
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


char	*ft_link_key_value(char *str, char **keys ,t_env_list *env_list)
{
	char	*expand;
	int		i;
	int		index;
	int 	j;
	//  const char *RED = "\033[0;31m";
    // const char *GREEN = "\033[0;32m";
    // const char *RESET = "\033[0m";
	// const char *blue = "\033[0;34m";
	
	//printf("the len is %d\n", ft_count_expand_len(str, keys, env_list));
	expand = ft_calloc(ft_count_expand_len(str, keys, env_list) + 1, sizeof(char));
	if (!expand)
		return (NULL);
	i = 0;
	index = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (str[i] && (str[i] == '$'))
			{
				//printf("%sYou found $ after $.%s\n", GREEN, RESET);
				j = ft_join_key(expand,keys[index], j);
				i += ft_strlen(keys[index]);
				index++;
			}else if (str[i] && str[i] == '?')
			{
				//printf("%syou found ? after $ and i = %d %s\n", RED, i,RESET);
				j = ft_join_key(expand, ft_itoa(exit_status), j);
				i++;
				index++;
				//printf("%syou ended i = %d str now at %s %s\n", RED, i,&str[i],RESET);
			}
			else
			{
				// printf("%sYou found normal char the j = %d and i = %i and str is at %s .%s\n", blue, j,i,&str[i],RESET);
				// printf("%sThe key is %s and the value is %s%s\n", blue, keys[index], ft_get_value(keys[index], env_list),RESET);
				j = ft_join_key(expand, ft_get_value(keys[index], env_list), j);
				i += ft_strlen(keys[index++]);
				//printf("%sThe i is now %d and the str is at %s%s\n", blue, i, &str[i],RESET);
			}
		}else
		{
			expand[j] = str[i];
			j++;
			i++;
		}
	}
	expand[j] = '\0';
	return (expand);
}
