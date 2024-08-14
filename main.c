/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/13 16:19:10 by aet-tale         ###   ########.fr       */
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

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		// rl_replace_line("", 0);
		rl_redisplay();
		exit_status = 1;
	}
}

void	close_heredocs(t_heredoc	*tmp)
{
	while (tmp)
	{
		close(tmp->fd);
		unlink(tmp->file_name);
		tmp = tmp->next;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	
	t_tokens_list	*tokens_list = NULL;
	t_command		*commands_list = NULL;
	t_env_list		*env_list = NULL;
	t_be_executed	*to_execute = NULL;
	//t_list_files	*list_of_files;
	t_pipe			*list_pipes = NULL;
	char			*line;
	//atexit(ft_check_leaks);

	(void) argc;
	(void) argv;
	(void) envp;

	signal(SIGINT,	sig_handler);
	signal(SIGQUIT, SIG_IGN);
	env_list = get_env_list(envp);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			// printf("exit\n");
			exit(exit_status);
			break ;
		}
		add_history(line);
		tokens_list = ft_init_token_list(line);
		if (ft_check_syntax(tokens_list))
		{
			ft_clean_tokens(tokens_list);
			exit_status = 258;
			continue ;
		}
		//ft_print_tokens_info(tokens_list);
		// continue	;
		// ft_expend_tokens(tokens_list, (env_list));
		ft_tokens_expand(tokens_list, env_list);
		commands_list = ft_split_to_command(tokens_list);
		//ft_print_command_info(commands_list);
		if (ft_init_heredoc(commands_list))
		{
			// free what should be freed
			close_heredocs(commands_list->heredoc_list);
			ft_clean_tokens(tokens_list);
			exit_status = 1;
			continue ;
		}
		// free command list
		// commands_list = ft_split_to_command(tokens_list);
		ft_open_files(commands_list);
		ft_select_files(commands_list);
		//list_of_files = give_list_files(tokens_list , commands_list);
		list_pipes = give_list_pipes(tokens_list);
		if (!list_pipes && count_list(commands_list) > 1)
		{
			ft_clean_tokens(tokens_list);
			exit_status = 1;
			continue ;
		}
		fill_command_paths(commands_list, env_list);
		//	print_list_files(list_of_files);
		//	ft_print_command_info(commands_list);
		//	continue ;
		to_execute = give_executed(commands_list, list_pipes, tokens_list, &env_list);
		if (to_execute == NULL)
		{
			ft_clean_tokens(tokens_list);
			exit_status = 1;
			continue ;
		}
		execute_things(to_execute);
		// close_files(list_of_files);
		ft_clean(to_execute);
	}
	return (exit_status);
}


