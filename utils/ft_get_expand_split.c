/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_expand_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:34:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 14:35:23 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_get_expand_split(char *value, t_env_list *env_list)
{
	char	**expanded;
	char	*expanded_value;

	if (!value)
		return (NULL);
	expanded_value = ft_expand(value, env_list);
	if (!expanded_value)
		return (NULL);
	expanded = ft_split_dil(expanded_value, ' ');
	free(expanded_value);
	return (expanded);
}
