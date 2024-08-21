/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:10:50 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 15:10:58 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**append_to_array(char **array, char *str)
{
	int		len;
	char	**new_array;
	int		i;

	i = 0;
	len = 0;
	new_array = NULL;
	while (array && array[len])
		len++;
	new_array = ft_calloc(len + 2, sizeof(char *));
	if (!new_array)
		return (NULL);
	while (i < len)
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[len] = ft_strdup(str);
	new_array[len + 1] = NULL;
	return (new_array);
}
