/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:31:14 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 12:32:34 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_pipes(t_pipe *list_pipes)
{
	t_pipe	*tmp;

	while (list_pipes)
	{
		tmp = list_pipes;
		close(tmp->fd[0]);
		close(tmp->fd[1]);
		list_pipes = list_pipes->next;
		free(tmp);
	}
}