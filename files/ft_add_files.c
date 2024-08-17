/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:17:11 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 12:32:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command_files	*ft_add_files(t_command_files **files_list, t_tokens_list *tokens, t_env_list *env_list)
{
	t_command_files	*files;
	t_tokens_list	*tmp;
	int				index;

	if (!tokens)
		return (NULL);
	tmp = tokens;
	index = 0;
	while (tmp)
	{
		if (ft_is_valid_redirection(tmp->type))
		{
			files = ft_create_files(&tmp, env_list);
			if (files)
				files->index = index;
			ft_files_addback(files_list, files);
		}
		if ( tmp && tmp->type == PIPE)
			index++;
		if (tmp)
			tmp = tmp->next;
	}
	return (*files_list);
}
