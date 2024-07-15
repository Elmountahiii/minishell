/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/15 13:16:27 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_check_leaks(void)
{
	system("leaks minishell");
}


int main(void)
{
	atexit(ft_check_leaks);
	char *line;
	char **tokens;
	int i;

	i = 0;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		add_history(line);
		tokens = ft_extract(line);
		while (tokens[i])
		{
			printf("token[%d]: '%s'\n", i, tokens[i]);
			i++;
		}
		ft_free_split(tokens, i);
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			free(line);
			break;
		}
		free(line);
		i = 0;
	}
	return 0;
}

// int main(void)
// {
// 	// "\"echo | cat\" \'Single quotes $HOME\'>file1.txt|\"cat  | ls  \">"
// 	char *line = "echo \"hello  $USER \" > file | grep h | cat << eof | cat >> file | echo \'done\'";
// 	printf("you need to allocate %d\n", ft_count_lexer_tokens(line));
// 	return 0;
// }

