/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_array_fromenv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:40:43 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/20 11:43:42 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**give_array_str(t_env_list *env_list)
{
	char	**env;
	char	**tmp;
	char	*line;

	env = NULL;
	line = NULL;
	while (env_list)
	{
		line = ft_join_three(env_list->key, "=", env_list->value);
		tmp = env;
		env = append_to_array(env, line);
		free(line);
		ft_clean_array(tmp);
		env_list = env_list->next;
	}
	return (env);
}
