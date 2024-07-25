/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:36:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/25 10:42:29 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_all_lines(char **split)
{
	int i;
	int j;
	int len;

	i= 0;
	len = 0;
	while (split && split[i])
	{
		j = 0;
		while (split[i] &&split[i][j])
			j++;	
		len += j;
		i ++;
	}

	return (len);
}

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
	// printf("###############\n");
	// printf("at start i = %d\n", i);
	len = ft_count_substr(str, i) - i;
	// printf("len = %d\n", len);
	j = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	// printf("!!!!!!!!!!!!!!!!!!\n");
	while (str[j + i] && j < len  )
	{
		if (str[j + i] == '\''  || str[j + i] == '\"')
		{
			len --;
			i ++;
		}
		else
		{
			sub[j] = str[j + i];
			j ++;
		}
		// printf("j = %d | i = %d\n", j, j + i );
	}
	// printf("###############\n");
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
char	*ft_clean_string(char **split)
{
	char *clean;
	int i;
	int j;
	int index;

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
