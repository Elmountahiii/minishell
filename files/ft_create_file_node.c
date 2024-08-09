/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:01:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/09 18:56:11 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command_files	*ft_create_file_node(char *file_name, t_token_type type)
{
	t_command_files	*new;

	new = ft_calloc(1,sizeof(t_command_files));
	if (!new)
		return (NULL);
	new->name = ft_strdup(file_name);
	new->type = type;
	new->next = NULL;
	return (new);
}