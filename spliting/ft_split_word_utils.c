/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_word_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:11:51 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 15:41:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_skip_word(char **line)
{
	int	i;

	i = 0;
	if (!*line)
		return (0) ;
	while (**line)
	{
		if (ft_is_space_v2(**line) || **line == '|' || **line == '>'
			|| **line == '<' || ft_is_quote(**line))
			break ;
		(*line)++;
		i++;
	}
	return (i);
}

char	*ft_create_word(char **line)
{
	char	*word;
	char	*tmp;
	int		len;	
	
	if (!*line)
		return (NULL);
	tmp = strdup(*line);
	len = ft_skip_word(&tmp);
	word = calloc((len + 1), sizeof(char));
	free(tmp - len);
	if (!word)
		return (NULL);
	strncpy(word, *line, len);
	word[len] = '\0';
	*line += len;
	return (word);
}

// int main()
// {
// 	char *line = "$?hello         youssef world";
// 	char *word = ft_create_word(&line);
// 	printf("word:%s\n", word);
// 	printf("line:%s\n", line);
// 	//system("leaks a.out");
// 	return 0;
// }
