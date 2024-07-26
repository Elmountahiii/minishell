/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/26 11:38:15 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_leaks(void)
{
	system("leaks minishell");
}

int main(void)
{
	//atexit(ft_check_leaks);
	//char **split;
	t_tokens_list	*tokens_list;
	// t_list_files	*list_of_files;
	t_command	*commands_list;
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
		else
		{
		commands_list = ft_split_to_command(tokens_list);
		
		
		ft_print_command_info(commands_list);
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			free(line);
			break;
		}
		}
		free(line);
	}
	return 0;
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
