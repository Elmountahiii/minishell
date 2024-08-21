/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:05:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 14:59:19 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_list(t_env_list *list)
{
	while (list != NULL)
	{
		printf("%s=", list->key);
		printf("%s\n", list->value);
		list = list->next;
	}
}
