/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_executed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:17 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 18:51:18 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_executed(t_command *command)
{
	if ((command->in_type == FILE_IO && command->in_file == NULL)
		|| (command->out_type == FILE_IO && command->out_file == NULL))
		return (0);
	if (command->is_ambiguous)
		return (0);
	if (command->fd_in == -1 || command->fd_out == -1)
		return (0);
	return (1);
}
