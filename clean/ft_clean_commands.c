/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:07:37 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/12 13:26:04 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_commands(t_command *commands_list)
{
	t_command	*tmp;

		tmp = commands_list;
			free(tmp->path);
		if (tmp->command_args)
			ft_free_array(tmp->command_args);
		free(tmp->in_file);
		free(tmp->out_file);
		free(tmp);
	
}
