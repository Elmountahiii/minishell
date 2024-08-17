/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_redirection_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:42:20 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 22:34:26 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_create_redirection(char **line)
{
	char	*redirection;
	int		len;

	len = 0;
	while ((*line)[len] == '>' || (*line)[len] == '<')
		len++;
	redirection = ft_substrl(*line, 0, len);
	*line += len;
	return (redirection);
}
