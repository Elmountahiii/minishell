/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:36:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 12:43:56 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_substr(char *str, int i)
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
	char  	is_quote;
	char     quote;
	
	is_quote = ft_is_quote(str[i]);
	if (is_quote)
		quote = str[i];
	else
		quote = 0;
	len = ft_count_substr(str, i) - i;
	j = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (str[j + i] && j < len)
	{
		if (is_quote && quote == str[j + i])
		{
			len --;
			i ++;
		}
		else
		{
			sub[j] = str[j + i];
			j ++;
		}
	}
	return (sub[j] = '\0' , sub);
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
char	*ft_clean_string(char **split)
{
	char	*clean;
	int		i;
	int		j;
	int		index;

	i = 0;
	clean = malloc(sizeof(char) * (ft_count_all_lines(split) + 1));
	if (!clean)
		return (NULL);
	index = 0;
	while (split && split[i])
	{
		j = 0;
		while (split[i] && split[i][j])
		{
			clean[index] = split[i][j];
			j++;
			index++;
		}
		i++;
	}
	clean[index] = '\0';
	return (clean);
}
