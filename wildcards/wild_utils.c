/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:17:11 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/22 22:40:16 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	one_part(char *pattern)
{
	int	i;

	i = 0;
	while (pattern[i] == '*')
		i++;
	while (pattern[i])
	{
		if (pattern[i] == '*')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strnstr_from_start(char *str, char *pattern, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && pattern[j] && i < len)
	{
		if (str[i] == pattern[j])
			j++;
		else
			j = 0;
		i++;
	}
	if (pattern[j] == '\0')
		return (1);
	return (0);
}

char	*get_uniltill_star(char *pattern)
{
	int	i;

	i = 0;
	while (pattern[i] && pattern[i] != '*')
		i++;
	return (ft_substr_orig(pattern, 0, i));
}

char	*skip_string(char *str, char *pattern)
{
	char	*name;
	char	*string_until_star;

	string_until_star = get_uniltill_star(pattern);
	if (ft_strncmp(string_until_star, str, ft_strlen(string_until_star)) == 0)
	{
		name = ft_substr_orig(str, ft_strlen(string_until_star),
				ft_strlen(str));
		free(string_until_star);
		free(str);
		return (name);
	}
	else
	{
		free(string_until_star);
		free(str);
		return (NULL);
	}
}
