/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/18 16:50:37 by yel-moun         ###   ########.fr       */
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
	t_tokens_list *tokens_list;
	t_command *commands_list;
	char *line;
	
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		add_history(line);
		tokens_list = ft_init_token_list(line);
	
		ft_print_tokens_info(tokens_list);
		commands_list = ft_split_to_command(tokens_list);
		int i = 0;
		while (commands_list)
		{
			printf("command N : %d\n", i);
			while (commands_list->command_args[i] != NULL)
			{
				printf("command arg : %s\n", commands_list->command_args[i]);
				i++;
			}
			i = 0;
			commands_list = commands_list->next;
		}
		
		
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			free(line);
			break;
		}
		free(line);
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

