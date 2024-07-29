/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 10:51:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_leaks(void)
{
	system("leaks minishell");
}

void	fill_in_out(t_command *commands_list, t_list_files *list_of_files, t_pipe *list_pipes)
{
	while (commands_list)
	{
		// printf("in file : %s\n", commands_list->in_file);
		assign_in(commands_list, list_of_files, list_pipes);
		assign_out(commands_list, list_of_files, list_pipes);
		commands_list = commands_list->next;
	}
}

int	main(void)
{
	t_tokens_list	*tokens_list;
	t_command		*commands_list;
	//atexit(ft_check_leaks);
	//char			**split;
	t_list_files	*list_of_files;
	t_pipe			*list_pipes;
	char			*line;
	
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		add_history(line);
		tokens_list = ft_init_token_list(line);
		if (ft_check_syntax(tokens_list))
			continue ;
		list_of_files = give_list_files(tokens_list);
		list_pipes = give_list_pipes(tokens_list);
		commands_list = ft_split_to_command(tokens_list, list_pipes);
		fill_in_out(commands_list, list_of_files, list_pipes);
		ft_print_command_info(commands_list);
		
		// print_list_pipes(list_pipes);
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			free(line);
			break;
		}
		free(line);
	}
	return (0);
}

// int main(int argc, char const *argv[], char  *envp[])
// {
// 	(void) argc;
// 	(void) argv;
// 	char *args[] = {
//     "awk", 
//     "{print $1}", 
//     "file.txt", 
//     NULL
// };

// 	execve("/usr/bin/awk", args, envp);
// 	return 0;
// }
