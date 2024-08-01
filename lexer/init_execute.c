/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:57:21 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/30 15:58:53 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_be_executed	*give_executed(t_command *commands_list, t_pipe *list_pipes, t_tokens_list *tokens_list)
{
	t_be_executed	*to_execute;

	to_execute = malloc(sizeof(t_be_executed));
	if (!to_execute)
		return (NULL);
	to_execute->commands_list = commands_list;
	to_execute->list_pipes = list_pipes;
	to_execute->tokens_list = tokens_list;
	return (to_execute);
}
