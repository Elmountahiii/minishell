/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 18:41:37 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		//rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 1;
	}
}

t_be_executed	*init(int argc, char *argv[])
{
	t_be_executed	*be_executed;

	(void) argc;
	(void) argv;
	be_executed = give_executed();
	if (!be_executed)
		return (NULL);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	return (be_executed);
}

void	final_clean(t_be_executed *exec)
{
	ft_clean_env(*exec->env_list);
	exec->env_list = NULL;
	free(exec);
}

char	*read_the_line(void)
{
	char	*line;

	line = readline("minishell$ ");
	if (!line)
		return (NULL);
	add_history(line);
	return (line);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_be_executed	*be_executed;
	t_env_list		*env_list;
	char			**tokens;
	char			*line;

	be_executed = init(argc, argv);
	if (!be_executed)
		return (1);
	env_list = get_env_list(envp);
	be_executed->env_list = &env_list;
	while (1)
	{
		line = read_the_line();
		if (!line)
			break ;
		tokens = ft_split_line(line);
		if (ft_setup(&be_executed, tokens))
		{
			ft_clean(be_executed, tokens, line);
			continue ;
		}
		execute_things(be_executed);
		ft_clean(be_executed, tokens, line);
	}
	return (final_clean(be_executed), g_exit_status);
}
