/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ambig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:33 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 12:16:13 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_all_spaces(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int ft_has_space_between_words(char *str)
{
    int i;
    int word_count;

    i = 0;
    word_count = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        // Skip spaces
        while (str[i] == ' ')
            i++;
        // If we found a word, increment word_count and skip the rest of the word
        if (str[i] != '\0')
        {
            word_count++;
            while (str[i] != ' ' && str[i] != '\0')
                i++;
        }
    }
    // If word_count is 2 or more, return 1 (true)
    return (word_count >= 2);
}

int	ft_has_spaces(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_ambig(t_command_files *files)
{
	if (!files)
		return (0);
	// if (!files->file_name)
	// 	return (1);
	if (files->file_name && ft_has_space_between_words(files->file_name))
		return (1);
	// if (files->file_name && ft_has_spaces(files->file_name))
	// 	return (1);
	// if (files->file_name && ft_strlen(files->file_name) == 0)
	// 	return (1);

	return (0);
}