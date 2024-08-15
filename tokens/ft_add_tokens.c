/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:59:50 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:57:27 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tokens_list	*ft_add_tokens(char **tokens)
{
	t_tokens_list	*list;

	list = NULL; 
	if (!tokens)
		return (NULL);
	while (*tokens)
	{
		ft_tokens_addback(&list, ft_create_token(*tokens));
		tokens++;
	}
	return (list);
}
