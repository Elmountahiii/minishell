/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:35:41 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 22:35:36 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_token(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '>' && str[1] && str[1] == '>')
		return (1);
	if (str[0] == '<' && str[1] && str[1] == '<')
		return (1);
	if (str[0] == '>')
		return (1);
	if (str[0] == '<')
		return (1);
	if (str[0] == '|')
		return (1);
	if (str[0] == '\'')
		return (1);
	if (str[0] == '\"')
		return (1);
	if (str[0] == '$')
		return (1);
	return (0);
}

t_token_type	ft_get_token_type(char *str)
{
	if (!str)
		return (WORD);
	if (str[0] == '>' && str[1] && str[1] == '>')
		return (APPEND);
	if (str[0] == '<' && str[1] && str[1] == '<')
		return (HEREDOC);
	if (str[0] == '<')
		return (REDIRECTION_IN);
	if (str[0] == '>')
		return (REDIRECTION_OUT);
	if (str[0] == '|')
		return (PIPE);
	if (str[0] == '\'')
		return (SINGLE_QUOTE_WORD);
	if (str[0] == '\"')
		return (DOUBLE_QUOTE_WORD);
	if (str[0] == '$')
		return (ENV);
	if (ft_is_space_v2(str[0]))
		return (SPACE_TOKEN);
	return (WORD);
}
