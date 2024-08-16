/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ambig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:33 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/16 11:01:31 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_all_spaces(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_has_spaces(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_ambig(t_command_files *files)
{
	if (!files)
		return (0);
	// if (!files->file_name)
	// 	return (1);
	if (files->file_name && ft_has_spaces(files->file_name))
		return (1);
	// if (files->file_name && ft_strlen(files->file_name) == 0)
	// 	return (1);

	return (0);
}