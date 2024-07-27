/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:11:14 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/27 16:17:14 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_list_pipes(t_pipe	*pipes)
{
	while (pipes)
	{
		printf("-----------------------------------------");
		printf("\n \n pipe: %d ", pipes->fd[0]);
		printf("pipe: %d\n", pipes->fd[1]);
		pipes = pipes->next;
	}
}
