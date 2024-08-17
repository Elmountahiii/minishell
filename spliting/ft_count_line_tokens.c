/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:26:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 22:21:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_line_tokens(char *line)
{
	int				count;
	t_token_type	type;

	count = 0;
	while (*line)
	{
		type = ft_get_token_type(line);
		if (type == WORD || type == ENV)
			ft_skip_word(&line);
		else if (type == SPACE_TOKEN)
			ft_skip_spacee(&line);
		else if (type == HEREDOC || type == APPEND)
			line += 2;
		else if (type == PIPE || type == REDIRECTION_OUT
			|| type == REDIRECTION_IN)
			line++;
		else if (type == DOUBLE_QUOTE_WORD || type == SINGLE_QUOTE_WORD)
			ft_skip_quotess(&line);
		else
			line++;
		count++;
	}
	return (count);
}
