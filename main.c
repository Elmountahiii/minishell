/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/24 21:12:06 by yel-moun         ###   ########.fr       */
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
	char **split;
	// t_tokens_list	*tokens_list;
	// t_list_files	*list_of_files;
	//t_command	*commands_list;
	char			*line;
	
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		add_history(line);
		// printf("line = %s\n", line);
		// printf("line words  = %d\n", ft_count_split_clean(line));
		
		split = ft_split_clean(line);
		int i = 0;
		while (split[i])
		{
			printf("split[%d] = %s\n", i, split[i]);
			i++;
		}
		// tokens_list = ft_init_token_list(line);
		// if (ft_check_syntax(tokens_list))
		// 	continue;
		// else
		// {
		// ft_print_tokens_info(tokens_list);
		// 	//printf("Syntax correct\n");
		// 	if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		// 	{
		// 		printf("exit\n");
		// 		free(line);
		// 		break;
		// 	}
		// }
		free(line);
	}
	return 0;
}

// int main()
// {
// 	char *str = "ls \"-       \"l\"a\"";
// 	// char *clean = ft_clean_string(str,SINGLE_QUOTE_WORD, ft_strlen(str));
// 	// printf("clean: %s\n", clean);
// 	printf("str = %s\n", str);
// 	printf("len = %d\n", ft_count_clean_string(str,SINGLE_QUOTE_WORD, ft_strlen(str)));
// 	return 0;
// }
