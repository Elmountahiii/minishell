/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:18 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char const *argv[], char *envp[])
{
	t_tokens_list	*tokens_list;
	t_command		*commands_list;
	t_env_list		*env_list;
	t_list_files	*list_of_files;
	t_pipe			*list_pipes;
	char			*line;

	(void) argc;
	(void) argv;

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
		tokens_list = ft_init_token_list(line, envp); // change it to our env
		//ft_print_tokens_info(tokens_list);

		if (ft_check_syntax(tokens_list))
			continue ;
		ft_expend_tokens(tokens_list, envp);
		ft_print_tokens_info(tokens_list);
		list_of_files = give_list_files(tokens_list);
		list_pipes = give_list_pipes(tokens_list);
		commands_list = ft_split_to_command(tokens_list, list_pipes);
		fill_in_out(commands_list, list_of_files, list_pipes);
		fill_command_paths(commands_list, env_list);
		ft_print_command_info(commands_list);
		execute_things(commands_list, list_of_files);
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


