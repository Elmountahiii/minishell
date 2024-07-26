/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/26 18:52:38 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_leaks(void)
{
	system("leaks minishell");
}

int	main(void)
{
	t_tokens_list	*tokens_list;
	t_command		*commands_list;
	//atexit(ft_check_leaks);
	//char **split;
	// t_list_files	*list_of_files;
	// t_pipe			*list_pipes;
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
		// init  redirections = done 
		// init  pipes 
		// fill the fds
		//ft_print_tokens_info(tokens_list);

		if (ft_check_syntax(tokens_list))
			continue;
		// list_of_files = give_list_files(tokens_list);
		// print_list_files(list_of_files);
		
		// list_pipes = give_list_pipes(tokens_list);
		// print_list_pipes(list_pipes);

		commands_list = ft_split_to_command(tokens_list);
		ft_print_command_info(commands_list);
		// else
		// {
		
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			free(line);
			break;
		}
		// }
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
