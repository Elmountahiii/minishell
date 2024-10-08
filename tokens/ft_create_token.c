/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:41:07 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 20:42:39 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tokens_list	*ft_create_token(char *str)
{
	t_tokens_list	*token;

	token = ft_calloc(1, sizeof(t_tokens_list));
	if (!token || !str)
		return (NULL);
	token->type = ft_get_token_type(str);
	token->value = ft_strdup(str);
	token->next = NULL;
	return (token);
}
