/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/05 18:12:20 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int exit_status = 0;

void	ft_check_leaks(void)
{
	system("leaks minishell");
}


int	main(int argc, char *argv[], char *envp[])
{
	t_tokens_list	*tokens_list = NULL;
	t_command		*commands_list = NULL;
	t_be_executed	*to_execute;
	t_env_list		*env_list;
	// t_list_files	*list_of_files;
	t_pipe			*list_pipes;
	char			*line;
	//atexit(ft_check_leaks);

	(void) argc;
	(void) argv;
	(void) envp;

	env_list = get_env_list(envp);
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
		//ft_print_tokens_info(tokens_list);
		// free then constinue
		if (ft_check_syntax(tokens_list))
			continue ;
		// printf("envii[0] = %s\n", envii[0]);
		// continue ;
		ft_expend_tokens(tokens_list, env_list); // change it to our env
		// list_of_files = give_list_files(tokens_list);
		list_pipes = give_list_pipes(tokens_list);
		commands_list = ft_split_to_command(tokens_list, list_pipes);
		fill_command_paths(commands_list, env_list);
		to_execute = give_executed(commands_list, list_pipes, tokens_list, &env_list);
		execute_things(to_execute);
		// close_files(list_of_files);
		// ft_clean_commands(commands_list);
		// free things
		// ft_print_command_info(commands_list);
		// print_list_pipes(list_pipes);
	}
	return (0);
}


