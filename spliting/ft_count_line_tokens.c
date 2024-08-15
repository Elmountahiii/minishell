/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:26:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 12:54:40 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count_line_tokens(char *line)
{
	int	count;

	count = 0;
	if (!line)
		return (0);
	while (*line)
	{
		if (ft_get_token_type(line) == WORD || ft_get_token_type(line) == ENV)
		{
			// if (ft_get_token_type(line) == ENV)
			// 	ft_skip_env(&line);
			// else 
				ft_skip_word(&line);
			count++;
		}
		else if (ft_get_token_type(line) == SPACE_TOKEN)
		{
			ft_skip_spacee(&line);
			count++;
		}
		else if (ft_get_token_type(line) == HEREDOC || ft_get_token_type(line) == APPEND)
		{
			line += 2;
			count++;
		}
		else if (ft_get_token_type(line) == PIPE || ft_get_token_type(line) == REDIRECTION_OUT
				|| ft_get_token_type(line) == REDIRECTION_IN)
		{
			line++;
			count++;			
		}
		else if (ft_get_token_type(line) == DOUBLE_QUOTE_WORD || ft_get_token_type(line) == SINGLE_QUOTE_WORD)
		{
			ft_skip_quotess(&line);
			count++;
		}
		else
			line++;
	}
	return (count);
}

// int main(int argc, char *argv[])
// {
// 	(void)argv;
// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <line>\n", argv[0]);
// 		return 1;
// 	}
// 	printf("the len is %d\n", ft_count_line_tokens(argv[1]));	
// 	return 0;
// }
