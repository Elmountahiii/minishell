/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:29:40 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/29 18:11:24 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_in_out(t_command *commands_list,
		t_list_files *list_of_files, t_pipe *list_pipes)
{
	while (commands_list)
	{
		assign_in(commands_list, list_of_files, list_pipes);
		assign_out(commands_list, list_of_files, list_pipes);
		commands_list = commands_list->next;
	}
}
