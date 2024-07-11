/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:30:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/11 16:44:02 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
void	ft_check_leaks(void)
{
	system("leaks minishell");
}
int main(void)
{
	atexit(ft_check_leaks);
	char *line;
	//char **split;
	//int i = 0;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		add_history(line);
		printf("line : %s\n", line);
		printf("count words : %d\n", ft_count_words(line));
		printf("super count words : %d\n", ft_count_words_v2(line));
		// split = ft_split(line);
		// while (split[i])
		// {
		// 	printf("split[%d] : %s\n", i, split[i]);
		// 	i++;
		// }
		// ft_free_split(split, i);
		if (ft_strlen(line) > 0 && ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("exit\n");
			free(line);
			break;
		}
		free(line);
		// i = 0;
	}
	//rl_clear_history();
	return 0;
}

// int main(void)
// {
// 	char *line = "\"echo | cat\" \'Single quotes $HOME\'>file1.txt|\"cat  | ls  \">";
// 	int result = ft_shift_space(line, 0);
// 	int i = 0;
// 	while (i < result)
// 	{
// 		printf("%c",line[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return 0;
// }

