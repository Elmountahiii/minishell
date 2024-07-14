/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexical_spliter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:29:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/14 13:03:27 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_allocate_split(char ***split, char *str)
{
	*split = malloc(sizeof(char *) * (ft_count_words_v2(str) + 1));
	if (!(*split))
		return (1);
	return (0);
}

int	ft_shift_quotes(char *str)
{
	int	i;
	int allocate;
	char quote;

	i = 0;
	allocate = 0;
	if (ft_is_quote(str[i]))
	{
		quote = str[i];
		i ++;
		allocate ++;
		while (str[i])
		{
			if (str[i] == quote)
				return (allocate + 1);
			else
				i ++;
			allocate ++;
		}
	}
	return (allocate);
}
int	ft_sub_alloc(char *str)
{
	int	i;
	bool	is_quote;
	char	quote;

	i = 0;
	if (!str)
		return (0);
	quote = 0;
	is_quote = ft_is_quote(str[i]);
	if (is_quote)
		return (ft_shift_quotes(str));
	else
	{
		while (str[i])
		{
			if (ft_is_quote(str[i]))
			{
				quote = str[i];
				i++;
				while (str[i])
				{
					if (str[i] == quote)
						return (i + 1);
					else
						i ++;
				}
			}else
			{
				if (ft_is_space_v2(str[i]) || ft_is_metachar(str[i]))
				{
					printf("i = %d\n", i);
					return (i);
				}
				else
					i ++;
			}

			// if (ft_is_quote(str[i]))
			// 	return (ft_shift_quotes(&str[i]) + i);
			// else if (ft_is_space_v2(str[i]) || ft_is_metachar(str[i]))
			// 	return (i);
			// else 
			// 	i ++;
		}	
	}
	return (i);
}


char *ft_substr_v2(char *str, int i)
{
	int		j;
	char	*sub;
	int 	allocate;

	j = 0;
	if (!str)
		return (NULL);
	allocate = ft_count_alloc(str,i);
	// printf("allocate = %d - for: %s \n", allocate, &str[i]);
	sub = malloc(sizeof(char) * (allocate + 1));
	if (!sub)
		return (NULL);
	while (j < allocate)
		sub[j++] = str[i++];
	sub[j] = '\0';
	return (sub);
}


char	**ft_lexical_spliter(char *str)
{
	char	**split;
	int		index;
	int		i;
	
	if (ft_allocate_split(&split, str))
		return (NULL);
	i = 0;
	index = 0;
	while (str && str[i])
	{
		if (!ft_is_space_v2(str[i]))
		{
			split[index] = ft_substr_v2(str, i);
			index ++;
			i+= ft_count_alloc(str, i);
		}
		else
			i ++;
		
	}
	
	return (split[index] = NULL, split);
}