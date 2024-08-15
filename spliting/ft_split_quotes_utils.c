/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:11:43 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:54:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_skip_quotess(char **line)
{
	int	i;
	char quote;

	i = 0;
	if (!*line)
		return (0);
	if(!ft_is_quote(**line))
		return (0);
	quote = **line;
	(*line)++;
	i++;
	while (**line)
	{
		if (**line == quote)
			break ;
		(*line)++;
		i++;
	}
	if (**line  && **line == quote)
	{
		(*line)++;
		i++;
	}
	return (i);
}

char	*ft_crate_quote(char **line)
{
	char	*quote;
	char	*tmp;
	int		len;

	if (!*line)
		return (NULL);
	tmp = strdup(*line);
	len = ft_skip_quotess(&tmp);
	quote = calloc((len + 1), sizeof(char));
	free(tmp - len);
	if (!quote)
		return (NULL);
	strncpy(quote, *line, len);
	quote[len] = '\0';
	*line += len;
	return (quote);
}

// int main()
// {
// 	char *line = "\"hello         youssef world\" 1337";
// 	char *quote = ft_crate_quote(&line);
// 	printf("quote:%s\n", quote);
// 	printf("line:%s\n", line);
// 	return 0;
// }
