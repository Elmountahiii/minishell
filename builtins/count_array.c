/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:25:32 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/18 13:13:08 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_array_str(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

int	is_in_list(char *key, t_env_list *env_list)
{
	t_env_list	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	error_handler(int *exit_stt, char *key, char *value, int procss)
{
	write(2, "minishell: export: `", 20);
	write(2, key, ft_strlen(key));
	write(2, "': not a valid identifier\n", 26);
	free(key);
	free(value);
	if (procss)
	{
		if (*exit_stt == 0)
			*exit_stt = 1;
	}
	else
	{
		if (exit_status == 0)
			exit_status = 1;
	}
}
