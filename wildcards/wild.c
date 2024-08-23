/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wild.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:17:11 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/23 13:09:02 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*skip_star_dill(char *str, char *pattern)
{
	char	*name;
	char	*string_until_star;
	int		start;

	start = 0;
	while (*pattern == '*')
		pattern++;
	string_until_star = get_uniltill_star(pattern);
	if (!str)
		return (NULL);
	if (ft_strnstr(str, string_until_star, ft_strlen(str)))
	{
		start = (ft_strnstr(str, string_until_star, ft_strlen(str))) - str
			+ ft_strlen(string_until_star);
		name = ft_substr_orig(str, start, ft_strlen(str));
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

char	*skip_a_part_name(char *pattern, char *str)
{
	if (pattern[0] != '*')
	{
		return (skip_string(str, pattern));
	}
	else if (pattern[0] == '*')
	{
		return (skip_star_dill(str, pattern));
	}
	return (NULL);
}

char	*skip_a_part_pattern(char *pattern)
{
	while (*pattern == '*')
		pattern++;
	while (*pattern && *pattern != '*')
		pattern++;
	return (pattern);
}

int	check_pattern(char *pattern, char *str)
{
	int		re_val;
	char	*hold_str;

	str = ft_strdup(str);
	hold_str = NULL;
	re_val = 0;
	if (pattern[0] == '*' && pattern[1] == '\0')
		return (1);
	while (str && pattern && *pattern && *str)
	{
		str = skip_a_part_name(pattern, str);
		if (!str || (one_part(pattern) && str[0]))
			continue ;
		pattern = skip_a_part_pattern(pattern);
		if (pattern[0] == '*' && pattern[1] == '\0')
			return (1);
	}
	if (!(*pattern) && !(*str))
		re_val = 1;
	else
		re_val = 0;
	free(str);
	return (re_val);
}

char	**print_current_directory_files(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**strs;

	strs = NULL;
	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		return (NULL);
	}
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (check_pattern(pattern, entry->d_name) && entry->d_name[0] != '.')
			strs = append_to_array(strs, entry->d_name);
		entry = readdir(dir);
	}
	closedir(dir);
	return (strs);
}
