/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/06 11:55:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int exit_status = 0;

void	ft_check_leaks(void)
{
	system("leaks minishell");
}

void close_files(t_list_files *list_of_files)
{
	t_list_files	*tmp;

	while (list_of_files)
	{
		tmp = list_of_files;
		list_of_files = list_of_files->next;
		close(tmp->fd);
		// free(tmp->file_name);
		free(tmp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	
	t_tokens_list	*tokens_list = NULL;
	t_command		*commands_list = NULL;
	t_be_executed	*to_execute;
	t_env_list		*env_list;
	t_list_files	*list_of_files;
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
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			break;
		}
		tokens_list = ft_init_token_list(line);
		// free then constinue
		if (ft_check_syntax(tokens_list))
			continue ;
		list_of_files = give_list_files(tokens_list);
		list_pipes = give_list_pipes(tokens_list);
		ft_expend_tokens(tokens_list, (env_list));
		commands_list = ft_split_to_command(tokens_list, list_pipes);
		ft_init_heredoc(commands_list);
		// ft_print_command_info(commands_list);
		// continue ;
		fill_command_paths(commands_list, env_list);
		to_execute = give_executed(commands_list, list_pipes, tokens_list, &env_list);
		execute_things(to_execute);
		close_files(list_of_files);
		// ft_clean_commands(commands_list);
		// free things
		// ft_print_command_info(commands_list);
		// print_list_pipes(list_pipes);
	}
	return (0);
}


