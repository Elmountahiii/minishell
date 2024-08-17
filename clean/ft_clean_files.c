/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:53:34 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 15:09:33 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_clean_files(t_command_files **files)
{
	t_command_files	*tmp;

	if (!files || !(*files))
		return ;
	while ((*files))
	{
		tmp = (*files)->next;
		close((*files)->fd);
		free((*files)->file_name);
		free((*files)->ambiguous_name);
		if ((*files)->files)
			ft_clean_array((*files)->files);
		free((*files));
		(*files) = tmp;
	}
}
