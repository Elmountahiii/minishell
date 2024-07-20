/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:35:15 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/20 13:18:05 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_list	*get_env_list(char	**env)
{
	t_env_list	*list;

	list = NULL;
	while (*env)
    {
		// printf("%s\n", *env);
		add_back_for_env(&list, *env);
		env++;
	}
	return list;
}