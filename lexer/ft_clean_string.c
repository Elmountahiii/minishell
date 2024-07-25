/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:36:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/25 10:02:04 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
int	ft_skip_clean_spaces(char *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int	ft_skip_quotes(char *str, int i)
{
	if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		if (str[i] == '\'')
			i++;
	}
	else if (str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
		if (str[i] == '\"')
			i++;
	}
	return (i);
}

int ft_count_substr(char *str, int i)
{
	if (str[i] && (str[i] == '\'' || str[i] == '\"'))
		i = ft_skip_quotes(str, i);
	else
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\'' && str[i] != '\"')
			i ++;
	}
	return (i);
}
int ft_count_split_clean(char *str)
{
    int words;
    int i;

    i = 0;
    words = 0;
    while (str && str[i])
    {
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i = ft_skip_quotes(str, i);
		else
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\'' && str[i] != '\"')
				i ++;
		}
		words++;
    }
    return words;
}

char *ft_clean_supstr(char *str, int i)
{
	int		len;
	char	*sub;
	int		j;

	len = ft_count_substr(str, i);
	printf("len = %d\n", len);
	j = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (str[j + i] && i < len )
	{
		if (str[j + i] == '\''  || str[j + i] == '\"')
			i ++;
		else
		{
			sub[j] = str[j + i];
			j ++;
		}
	}
	sub[j] = '\0';
	return (sub);
}
char **ft_split_clean(char *str)
{
	char	**split;
	int		index;
	int		i;

	split = malloc(sizeof(char *) * (ft_count_split_clean(str) + 1));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (str && str[i])
	{
		split[index] = ft_clean_supstr(str, i);
		if (!split[index])
			return (ft_free_split(split, index), NULL);
		i = ft_count_substr(str, i);
		index ++;
	}
	return (split[index] = NULL, split);
}
char	*ft_clean_string(char *str, t_token_type type, int len)
{
	(void) type;
	(void) len;
	return (str);
}
