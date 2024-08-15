/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_skip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:07:56 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:37:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_token_skip(t_tokens_list **tokens, t_token_type type)
{
	while (*tokens && (*tokens)->type == type)
		*tokens = (*tokens)->next;
}
