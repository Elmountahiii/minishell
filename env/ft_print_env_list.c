/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:05:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 18:36:00 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_list(t_env_list *list)
void	print_env_list(t_env_list *list)
{
	while (list != NULL)
	{
		printf("%s=", list->key);
		printf("%s\n", list->value);
		list = list->next;
		printf("%s=", list->key);
		printf("%s\n", list->value);
		list = list->next;
	}
}
