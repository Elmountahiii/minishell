/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:34:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/23 12:10:16 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_setup_tokens(t_be_executed **exec, char **tokens)
{
	(*exec)->tokens_list = ft_add_tokens(tokens);
	if (ft_check_syntax((*exec)->tokens_list))
	{
		g_exit_status = 258;
		return (1);
	}
	return (0);
}

int	ft_setup_heredoc(t_be_executed **exec)
{
	(*exec)->heredoc_list = ft_add_heredoc(&(*exec)->heredoc_list,
			(*exec)->tokens_list);
	if (ft_open_heredoc((*exec)->heredoc_list,*(*exec)->env_list))
	{
		g_exit_status = 1;
		return (1);
	}
	return (0);
}

int	ft_setup_files(t_be_executed **exec)
{
	(*exec)->files_list = ft_add_files(&(*exec)->files_list,
			(*exec)->tokens_list,
			*(*exec)->env_list);
	ft_open_files((*exec)->files_list);
	return (0);
}

int	ft_setup_pipes(t_be_executed **exec)
{
	(*exec)->list_pipes = give_list_pipes((*exec)->tokens_list);
	if (!(*exec)->list_pipes && count_list((*exec)->commands_list) > 1)
	{
		g_exit_status = 1;
		return (1);
	}
	return (0);
}

int	ft_setup(t_be_executed **exec, char **tokens)
{
	if (ft_setup_tokens(exec, tokens))
		return (1);
	if (ft_setup_heredoc(exec))
		return (1);
	ft_setup_files(exec);
	(*exec)->commands_list = ft_add_command(&(*exec)->commands_list,
			(*exec)->tokens_list, *(*exec)->env_list);
	ft_command_assign_fds((*exec)->commands_list, (*exec)->files_list,
		(*exec)->heredoc_list);
	fill_command_paths((*exec)->commands_list, *(*exec)->env_list);
	if (ft_setup_pipes(exec))
		return (1);
	(*exec)->list_size = count_list((*exec)->commands_list);
	return (0);
}
