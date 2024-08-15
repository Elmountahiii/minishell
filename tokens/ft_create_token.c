/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:41:07 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:37:34 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tokens_list *ft_create_token(char *str)
{
	t_tokens_list	*token;
	
	token = calloc(1, sizeof(t_tokens_list));
	if (!token || !str)
		return (NULL);
	token->type = ft_get_token_type(str);
	token->value = strdup(str);
	token->next = NULL;
	return (token);
}
