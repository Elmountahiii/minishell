/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:20:08 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 14:30:53 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_files_addback(t_command_files **files_list, t_command_files *new)
{
	t_command_files	*tmp;

	if (!files_list || !new)
		return ;
	if (!*files_list)
	{
		*files_list = new;
		return ;
	}
	tmp = *files_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
