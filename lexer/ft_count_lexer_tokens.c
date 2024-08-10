/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lexer_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:48:16 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 19:39:40 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_skip_spaces(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && ft_check_space(str[i]))
		i++;
	return (i);
}

int	ft_skip_special(char *str)
{
	int		i;
	char	special;

	if (!str)
		return (0);
	special = str[0];
	i = 0;
	if (ft_check_space(special))
		return (ft_skip_spaces(str));
	i = 1;
	if (special == '<' || special == '>')
	{
		if (str[i])
		{
			if (str[i] == special)
				i = 2;
		}
	}
	return (i);
}

int	ft_skip_until_quote(char *str)
{
	int		i;
	char	quote;

	if (!str || !ft_is_quote(str[0]))
		return (0);
	i = 0;
	quote = str[0];
	i++;
	while (str[i])
	{
		if (str[i] == quote)
			break ;
		i++;
	}
	if (str[i] && str[i] == quote)
		i++;
	return (i);
}

int	ft_skip(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (ft_is_quote(str[i]))
		return (ft_skip_until_quote(str));
	while (str[i])
	{
		if (ft_is_special_char(str[i]) || ft_is_quote(str[i]))
			break ;
		i ++;
	}
	return (i);
}

int	ft_count_skip(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (!ft_is_special_char(str[i]))
		i += ft_skip(str + i);
	else
		i += ft_skip_special(str + i);
	return (i);
}

int	ft_count_lexer_tokens(char *str)
{
	int	tokens;
	int	i;

	if (!str)
		return (0);
	i = 0;
	tokens = 0;
	while (str[i])
	{
		if (!ft_is_special_char(str[i]))
			i += ft_skip(str + i);
		else
			i += ft_skip_special(str + i);
		tokens++;
	}
	return (tokens);
}
