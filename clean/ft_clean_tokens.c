/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:08:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 16:48:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_tokens(t_tokens_list **tokens_list)
{
	t_tokens_list	*tmp;

	if (!tokens_list || !(*tokens_list))
		return ;
	while ((*tokens_list))
	{
		tmp = (*tokens_list)->next;
		free((*tokens_list)->value);
		(*tokens_list)->value = NULL;
		free((*tokens_list));
		(*tokens_list) = tmp;
	}
}
