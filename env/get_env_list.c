/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:53:46 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 15:00:53 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_list	*get_env_list(char	**env)
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
