/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexical_spliter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:29:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/12 11:36:13 by yel-moun         ###   ########.fr       */
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

	i = 0;
	allocate = 0;
	if (ft_is_quote(str[i]))
	{
		i ++;
		allocate ++;
		while (str[i] && !ft_is_quote(str[i]))
		{
			i ++;
			allocate ++;
		}
		if (ft_is_quote(str[i]))
			allocate ++;
	}
	return (allocate);
}
int	ft_sub_alloc(char *str)
{
	int	i;
	bool quote;

	i = 0;
	if (!str)
		return (0);
	quote = ft_is_quote(str[i]);
	if (quote)
		return (ft_shift_quotes(str));
	else
	{
		while (str[i])
		{
			if (ft_is_quote(str[i]))
				return (ft_shift_quotes(&str[i]) + i);
			else if (ft_is_space_v2(str[i]) || ft_is_metachar(str[i]))
				return (i);
			else 
				i ++;
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
	if (ft_is_metachar(str[i]))
	{
		sub = malloc(sizeof(char) * 3);
		if (!sub)
			return (NULL);
		while (j < 2)
		{
			if (ft_is_metachar(str[i]))
				sub[j++] = str[i++];
			else
			{
				sub[j++] = '\0';
				i++;
			}
		}
		//printf("sub : %s len %d j = %d \n", sub,ft_strlen(sub), j);
		// sub[j] = '\0';
		return (sub);
	}
	allocate = ft_sub_alloc(&str[i]);
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
			if (ft_is_metachar(str[i]))
			{
				if (str[i + 1])
				{
					if ((str[i] == '>' && str[i + 1] == '>') || (str[i] == '<' && str[i + 1] == '<'))
						i += 2;
					else
						i ++;
				}
				else
					i ++;	
				}
			else
				i += ft_sub_alloc(&str[i]);
		}
		else
			i ++;
		
	}
	
	return (split[index] = NULL, split);
}