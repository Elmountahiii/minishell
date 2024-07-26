/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:25:28 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/26 16:32:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int ft_count_line_single_quotes(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count++;
		i++;
	}
	return (count);
}

int	ft_count_line_double_quotes(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			count++;
		i++;
	}
	return (count);
}


int ft_check_quotes_syntax(char *line)
{
	int single_quotes_count;
	int double_quotes_count;
	
	double_quotes_count = ft_count_line_double_quotes(line);
	single_quotes_count = ft_count_line_single_quotes(line);
	if (double_quotes_count % 2 != 0 || single_quotes_count % 2 != 0)
		return (1);
	return (0);
}
