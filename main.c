/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/21 19:59:40 by aet-tale         ###   ########.fr       */
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
	t_tokens_list	*tokens_list;
	t_list_files	*list_of_files;
	// t_command	*commands_list;
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
		tokens_list = ft_init_token_list(line);
		ft_print_tokens_info(tokens_list);
		list_of_files = give_list_files(tokens_list);
		print_list_files(list_of_files);
		// printf("--------------------\n");
		// commands_list = ft_split_to_command(tokens_list);
		// ft_print_command_info(commands_list);
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

