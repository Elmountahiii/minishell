/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:14:07 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/03 12:14:20 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_built_in(char	*command)
{
	if (ft_strcmp(command, "echo") == 0)
		return (1);
	else if (ft_strcmp(command, "cd") == 0)
		return (1);
	else if (ft_strcmp(command, "pwd") == 0)
		return (1);
	else if (ft_strcmp(command, "export") == 0)
		return (1);
	else if (ft_strcmp(command, "unset") == 0)
		return (1);
	else if (ft_strcmp(command, "env") == 0)
		return (1);
	else if (ft_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}
