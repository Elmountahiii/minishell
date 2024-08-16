/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/16 16:26:46 by yel-moun         ###   ########.fr       */
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
		//rl_replace_line("", 0);
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
	(void) argc;
	(void) argv;
	(void) envp;
	t_be_executed	*be_executed;
	t_env_list		*env_list = NULL;
	char **tokens;
	char * line;

	tokens = NULL;
	env_list = get_env_list(envp);
	signal(SIGINT,	sig_handler);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		add_history(line);
		tokens = ft_split_line(line);
		be_executed = give_executed();
		be_executed->env_list = &env_list;
		be_executed->tokens_list = ft_add_tokens(tokens);
		if (ft_check_syntax(be_executed->tokens_list))
		{
			exit_status = 258;
			continue ;
		}
		be_executed->heredoc_list = ft_add_heredoc(&be_executed->heredoc_list, be_executed->tokens_list);
		ft_open_heredoc(be_executed->heredoc_list,env_list);
		be_executed->files_list = ft_add_files(&be_executed->files_list, be_executed->tokens_list, env_list);
		//printf("\nhere\n");
		ft_open_files(be_executed->files_list);
		//ft_printf_files(be_executed->files_list);
		//ft_print_tokens(be_executed->tokens_list);
		be_executed->commands_list = ft_add_command(&be_executed->commands_list, be_executed->tokens_list,env_list);
		ft_command_assign_fds(be_executed->commands_list, be_executed->files_list, be_executed->heredoc_list);
		fill_command_paths(be_executed->commands_list, env_list);
		be_executed->list_pipes =  give_list_pipes(be_executed->tokens_list);
		be_executed->list_size = count_list(be_executed->commands_list);
		// ft_print_commands(be_executed->commands_list);
		// continue ;
		execute_things(be_executed);
	}
	return (exit_status);
}


