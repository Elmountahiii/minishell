/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:02:24 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/05 15:13:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_tokens(t_tokens_list *tokens_list)
{
	t_tokens_list *tmp;

	while (tokens_list)
	{
		free(tokens_list->value);
		tmp = tokens_list;
		tokens_list = tokens_list->next;
		free(tmp);
	}
}
