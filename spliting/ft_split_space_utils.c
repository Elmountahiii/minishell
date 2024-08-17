/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:09:16 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 20:41:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_skip_spacee(char **line)
{
	int	i;

	i = 0;
	if (!*line)
		return (0);
	while (**line)
	{
		if (!ft_is_space_v2(**line))
			break ;
		(*line)++;
		i++;
	}
	return (i);
}

char	*ft_create_space(char **line)
{
	char	*space;
	char	*tmp;
	int		len;

	if (!*line)
		return (NULL);
	tmp = ft_strdup(*line);
	len = ft_skip_spacee(&tmp);
	space = ft_calloc((len + 1), sizeof(char));
	free(tmp - len);
	if (!space)
		return (NULL);
	ft_strncpy(space, *line, len);
	space[len] = '\0';
	*line += len;
	return (space);
}

// int main()
// {
// 	char *line = "                     hello         youssef world";
// 	char *space = ft_create_space(&line);
// 	printf("space:%s\n", space);
// 	printf("line:%s\n", line);
// 	//system("leaks a.out");
// 	return 0;
// }