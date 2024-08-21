/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increament_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:04:16 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 12:19:16 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	increament_elems(t_pipe **list_pipes, int *i, t_pipe **previous)
{
	*previous = *list_pipes;
	*list_pipes = (*list_pipes)->next;
	(*i)++;
}
