/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:50:44 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/15 12:50:53 by aet-tale         ###   ########.fr       */
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
