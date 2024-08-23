/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:39:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/23 12:14:27 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_expand_value_with_quotes_or_equal(char *value)
{
	char	**expanded;
	char	*tmp;

	expanded = ft_calloc(2, sizeof(char *));
	if (!expanded)
		return (NULL);
	tmp = NULL;
	if (ft_strchr(value, '=') && ft_has_any_quotes(value))
		tmp = ft_remove_all_quotes(value);
	else if (ft_has_any_quotes(value))
		tmp = ft_remove_all_quotes(value);
	else
		tmp = ft_strdup(value);
	expanded[0] = ft_strdup(tmp);
	expanded[1] = NULL;
	free(value);
	free(tmp);
	return (expanded);
}

char	**ft_expand_value_without_quotes_or_equal(char *value)
{
	char	**expanded;
	char	*tmp;

	tmp = NULL;
	if (ft_has_any_quotes(value))
		tmp = ft_remove_all_quotes(value);
	else
		tmp = ft_strdup(value);
	expanded = ft_split_dil(tmp, ' ');
	free(value);
	free(tmp);
	return (expanded);
}

char	**ft_expand_value(char *value)
{
	char	**wild;
	char	*tmp;

	if (ft_has_quotes(value) || ft_strchr(value, '='))
		return (ft_expand_value_with_quotes_or_equal(value));
	else
	{
		if (ft_strchr(value, '*'))
		{
			if (ft_has_any_quotes(value))
				tmp = ft_remove_all_quotes(value);
			else
				tmp = ft_strdup(value);
			wild = print_current_directory_files(tmp);
			free(tmp);
			if (!wild)
				return (ft_expand_value_without_quotes_or_equal(value));
			else
				return (free(value), wild);
		}
		else
			return (ft_expand_value_without_quotes_or_equal(value));
	}
}
