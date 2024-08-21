/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:38:15 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/21 18:38:19 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_list	*get_env_list(char **env)
{
	t_env_list	*list;

	list = NULL;
	while (*env)
	{
		add_back_for_env(&list, *env);
		env++;
	}
	return (list);
}
