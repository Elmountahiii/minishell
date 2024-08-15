/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_addback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:43:00 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:38:02 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tokens_addback(t_tokens_list **alst, t_tokens_list *new)
{
	t_tokens_list	*last;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = *alst;
	while (last->next)
		last = last->next;
	last->next = new;
}
