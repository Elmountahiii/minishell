/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_other_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:35:21 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/21 18:35:22 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_other_pipes(t_command	*command, t_pipe *list_pipes)
{
	t_pipe	*tmp;

	tmp = list_pipes;
	while (tmp)
	{
		if (tmp->fd[0] != command->fd_in)
			close(tmp->fd[0]);
		if (tmp->fd[1] != command->fd_out)
			close(tmp->fd[1]);
		tmp = tmp->next;
	}
}
