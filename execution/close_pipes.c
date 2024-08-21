/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:44:56 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 11:45:04 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_pipes(t_pipe *list_pipes)
{
	t_pipe	*tmp;

	tmp = list_pipes;
	while (tmp)
	{
		close(tmp->fd[0]);
		close(tmp->fd[1]);
		tmp = tmp->next;
	}
}
