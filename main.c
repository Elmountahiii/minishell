/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/11 20:43:02 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exit_status = 0;

void	ft_check_leaks(void)
{
	system("leaks minishell");
}

void close_files(t_list_files	*list_of_files)
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
	t_env_list		*env_list;
	t_be_executed	*to_execute;
	//t_list_files	*list_of_files;
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
			break ;
		add_history(line);
		tokens_list = ft_init_token_list(line);
		if (ft_check_syntax(tokens_list))
		{
			ft_clean_tokens(tokens_list);
			exit_status = 258;
			continue ;
		}
		ft_tokens_expand(tokens_list, env_list);
		ft_print_tokens_info(tokens_list);
		// continue	;
		// ft_expend_tokens(tokens_list, (env_list));
		commands_list = ft_split_to_command(tokens_list);
		//ft_print_command_info(commands_list);
		ft_init_heredoc(commands_list);
		ft_open_files(commands_list);
		ft_select_files(commands_list);
		list_pipes = give_list_pipes(tokens_list);
		fill_command_paths(commands_list, env_list);
		to_execute = give_executed(commands_list, list_pipes, tokens_list, &env_list);
		execute_things(to_execute);
		ft_clean(to_execute);
		free(to_execute);
	}
	return (exit_status);
}


