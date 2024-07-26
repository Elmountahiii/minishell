/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_until_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:01:16 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/26 11:03:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_list_skip_spaces(char **tokens,int index)
{
	while (tokens[index])
	{
		if (ft_is_all_space(tokens[index]))
			break;
		index++;
	}
	return (index);
}


char *ft_join_until_space(char **tokens, int index)
{
	char *new_str;
	
	new_str = NULL;
	while (tokens[index])
	{
		if (ft_is_all_space(tokens[index]) )
			break;
		new_str = ft_strjoin(new_str, tokens[index]);
		index++;
	}
	return (new_str);
}
